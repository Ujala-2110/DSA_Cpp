#include <iostream>
using namespace std;

//In decreeasing order
void Print_num(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    Print_num(n - 1);
}

//In Increasing order
void Print_num(int n)
{
    if (n == 0)
        return;

    Print_num(n - 1);
    cout << n << " ";
}

int main()
{
    int num = 10;
    Print_num(num);
    return 0;
}