#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
int numberOfPaths(int m, int n)
{
    if (m == 0 && n == 0) return 1;

    if (m < 0 || n < 0)  return 0;

    // If diagonal movements are allowed then the last addition is required.
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
    // + numberOfPaths(m-1, n-1);
}
*/

//Memoization
/*
int numberOfPaths(int m, int n ,vector<vector<int>>&dp)
{
    if (m == 0 && n == 0) return 1;

    if (m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    // If diagonal movements are allowed then the last addition is required.
    return dp[m][n] = numberOfPaths(m - 1, n,dp) + numberOfPaths(m, n - 1,dp);
    // + numberOfPaths(m-1, n-1);
}
TC-> O(m*n) ans space -> O(m*n) + O(m-1 + n-1)path length
*/

//Tabulation
int numberOfPaths(int m, int n)
{
    int dp[m+1][n+1] = {0};

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 && j == 0)  dp[i][j] = 1; //For reaching (0,0) there is only one way

            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)  up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    int m = 2, n = 2;
    // cout << numberOfPaths(m - 1, n - 1); //Recursion
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << numberOfPaths(m - 1, n - 1,dp);
    cout << numberOfPaths(m - 1, n - 1);
    return 0;
}
