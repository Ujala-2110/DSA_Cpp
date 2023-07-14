#include <bits/stdc++.h>
using namespace std;

// Mine memoization
/*
int func(int i, int j, int arr[], bool flag, vector<vector<int>> &dp)
{
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    if (flag)
    {
        return dp[i][j] = max(arr[i] + func(i + 1, j, arr, !flag, dp), arr[j] + func(i, j - 1, arr, !flag, dp));
    }

    else
    {
        return dp[i][j] = min(func(i + 1, j, arr, !flag, dp), func(i, j - 1, arr, !flag, dp));
    }
}
*/

// Memoization
/*
int func(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if(i+1 == j) return max(arr[i],arr[j]);

    if (dp[i][j] != -1) return dp[i][j];

    //arr[i.....j] rem coin = arr[i+1.....j] (if arr[i] is chosen)
    int l = arr[i] + min(func(i + 1, j - 1, arr, dp), func(i + 2, j, arr, dp));

    //arr[i.....j] rem coin = arr[i.....j-1] (if arr[j] is chosen)
    int r = arr[j] + min(func(i + 1, j - 1, arr, dp), func(i, j - 2, arr, dp));

    return dp[i][j] = max(l, r);
}

min(func(i + 1, j - 1, arr, dp), func(i + 2, j, arr, dp)) this means is that the opponent will leave minimum value to us
*/

// Tabulation
int func(int n, int arr[], vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++) dp[i][i+1] = max(arr[i],arr[i+1]);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            int l = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
            int r = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

            dp[i][j] = max(l, r);
        }
    }

    return dp[0][n - 1];
}
int main()
{
    int arr[] = {5, 3, 7, 10};
    int n = sizeof(arr) / sizeof(int);
    // bool flag = true;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // cout<< func(0, n - 1, arr, flag, dp);

    // cout<< func(0, n - 1, arr, dp); //Memoization

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    cout<< func(n,arr,dp);

}