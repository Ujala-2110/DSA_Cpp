#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    stack<int> tmpstack;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();

        while (!tmpstack.empty() && tmp < tmpstack.top())
        {
            s.push(tmpstack.top());
            tmpstack.pop();
        }
        tmpstack.push(tmp);
    }
    return tmpstack;
}

void sortArrayUsingStacks(int arr[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }
    stack<int> tmpStack = sortStack(s);

    for (int i = 0; i < n; i++)
    {
        arr[i] = tmpStack.top();
        tmpStack.pop();
    }
}

int main()
{
    int arr[] = {10, 5, 15, 45, 25, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArrayUsingStacks(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
