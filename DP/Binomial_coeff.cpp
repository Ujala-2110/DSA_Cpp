#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// Recursion
/*
int binomialCoeff(int n, int k)
{
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}
*/

// Memoization
/*
int binomialCoeff(int n, int k,vector<vector<int>>&dp)
{
    if (k > n) return 0;

    if (k == 0 || k == n) return 1;

    if(dp[n][k] != -1) return dp[n][k] % mod;

    return dp[n][k] = (binomialCoeff(n - 1, k - 1,dp) + binomialCoeff(n - 1, k,dp)) % mod;
}
*/

// Tabulation
int binomialCoeff(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
    }

    return dp[n][k];
}

int main()
{
    int n = 5, k = 2;
    // cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k);
    // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k);
    return 0;
}