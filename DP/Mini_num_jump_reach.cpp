// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

// Memoization
/*
int func(int ind, int arr[], int n, vector<int> &dp)
{
    if (ind == 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int ans = INT_MAX;
    for (int j = 0; j < ind; j++)
    {
        if (ind <= (j + arr[j]))
        ans = min(ans + 0LL, 1LL + func(j, arr, n, dp));
    }

    return dp[ind] = ans;
}
*/

// Tabulation
int func(int arr[], int n)
{
    vector<int>dp(n,inf);
    if (n == 1) return 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]))
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    return dp[n-1];
}

int minJumps(int arr[], int n)
{
    // vector<int> dp(n, -1);
    // if (func(n - 1, arr, n, dp) != INT_MAX) return func(n - 1, arr, n, dp);
    // else
    // return -1;
    if (func(arr,n) != INT_MAX) return func(arr,n);
    else
    return -1;
}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}