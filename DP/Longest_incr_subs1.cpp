#include <bits/stdc++.h>
using namespace std;

// Tabulation
/*
int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
            lis[i] = max(lis[i], lis[j] + 1);
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}
*/
int lis(int arr[], int n)
{
    int dp[n + 1];
    for (int i = 1; i <= n; i++) dp[i] = INT_MAX;

    dp[0] = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(dp, dp + n + 1, arr[i]) - dp;
        if (arr[i] > dp[idx - 1] && arr[i] < dp[idx + 1]) dp[idx] = arr[i];
    }

    int ma = 0;
    for (int i = n; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
        {
            ma = i;
            break;
        }
    }

    return ma;
}
// O(NlogN)

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));

    return 0;
}
