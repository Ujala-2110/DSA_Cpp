// C++ program for a linear time solution for stock
// span problem without using stack
#include <iostream>
#include <stack>
using namespace std;

// An efficient method to calculate stock span values
// implementing the same idea without using stack
void calculateSpan(int price[], int n, int S[])
{
    // Span value of first element is always 1
    S[0] = 1;

    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++)
    {
        int counter = 1;
        while ((i - counter) >= 0 && price[i] >= price[i - counter])
        {
            counter += S[i - counter];
        }
        S[i] = counter;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);

    return 0;
}
