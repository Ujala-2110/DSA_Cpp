#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int findCnt(int set[], int n, int sum)
{
    if (sum == 0) return 1;
    if (n == 0) return set[0] == sum;

    int notpick = findCnt(set, n - 1, sum);
    int pick = 0;

    if (set[n] <= sum)
    pick = findCnt(set, n - 1, sum - set[n]);

    return pick + notpick;
}
*/

// Memoization
/*
int findCnt(int set[], int n, int sum,vector<vector<int>>&dp)
{
    if (sum == 0) return 1;
    if (n == 0) return set[0] == sum;

    if(dp[n][sum] != -1) return dp[n][sum];
    int notpick = findCnt(set, n - 1, sum,dp);
    int pick = 0;
    if (set[n] <= sum)
    pick = findCnt(set, n - 1, sum - set[n],dp);

    return dp[n][sum] =  pick + notpick;
}
*/

int main()
{
    int arr[] = {3, 3, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    // int x = 6;
    int sum = 6;

    // vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));
    // cout << findCnt(arr, n - 1, x, dp);

    for (int i = 0; i < n; i++) dp[i][0] = 1;

    if(arr[0] <= sum) dp[0][arr[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
            pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick + notpick;
        }
    }

    cout<< dp[n-1][sum];

    return 0;
}