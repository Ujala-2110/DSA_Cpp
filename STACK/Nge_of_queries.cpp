#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int index)
{
    stack<int> s;
    int nge[n];
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
        {
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }

    return (nge[index] == -1 ? -1 : arr[nge[index]]);
}

int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << solve(arr, n, 3) << " ";
    cout << solve(arr, n, 6) << " ";
    cout << solve(arr, n, 5) << " ";
    cout << solve(arr, n, 4) << " ";
    cout << solve(arr, n, 1) << " ";
    return 0;
}