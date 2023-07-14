#include <iostream>
using namespace std;

int fib(int num)
{
    if (num == 0)
        return 0;
    if (num == 1 || num == 2)
        return 1;

    return (fib(num - 1) + fib(num - 2));
}

int main()
{
    int n = 5;
    cout << "Fibonacci series of 5 numbers is: ";
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    return 0;
}