#include <bits/stdc++.h>
using namespace std;

int minOperation(int arr[], int n)
{
    int mx=0;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
        ump[arr[i]]++;

    for (int i = 0; i < n; i++)
         mx = max(mx, ump[arr[i]]);

    return n - mx;
}

int main()
{
    int arr[] = {1, 1, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minOperation(arr, n);
    return 0;
}