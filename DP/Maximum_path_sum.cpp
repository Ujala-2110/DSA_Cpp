#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int FindMaxpath(int i, int j, vector<vector<int>> &Matrix)
{
    if (j < 0 || j >= Matrix[0].size())  return -1e8;
    if (i == 0)  return Matrix[0][j];

    int up = Matrix[i][j] + FindMaxpath(i - 1, j, Matrix);
    int ld = Matrix[i][j] + FindMaxpath(i - 1, j - 1, Matrix);
    int rd = Matrix[i][j] + FindMaxpath(i - 1, j + 1, Matrix);

    return max(up, max(ld, rd));
}
*/

// Memoization
/*
int FindMaxpath(int i, int j, vector<vector<int>> &Matrix,vector<vector<int>>&dp)
{
    if (j < 0 || j >= Matrix[0].size())  return -1e8;
    if (i == 0)  return Matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int up = Matrix[i][j] + FindMaxpath(i - 1, j, Matrix,dp);
    int ld = Matrix[i][j] + FindMaxpath(i - 1, j - 1, Matrix,dp);
    int rd = Matrix[i][j] + FindMaxpath(i - 1, j + 1, Matrix,dp);

    return dp[i][j] =  max(up, max(ld, rd));
}
*/

int main()
{

    vector<vector<int>> Matrix{{10, 10, 2, 0, 20, 4}, {1, 0, 0, 30, 2, 5}, {0, 10, 4, 0, 2, 0}, {1, 0, 2, 20, 0, 4}};

    int n = Matrix.size();
    int m = Matrix[0].size();
    int maxi = -1e5;
    // for (int j = 0; j < m; j++)
    // maxi = max(maxi, FindMaxpath(n - 1, j, Matrix)); //Recursion
    // vector<vector<int>>dp(n,vector<int>(m,-1)); //Memoization

    vector<vector<int>> dp(n, vector<int>(m, 0)); // Tabulation
    for (int j = 0; j < m; j++)
    dp[0][j] = Matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = Matrix[i][j] + dp[i - 1][j];
            int ld = Matrix[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld += -1e5;
            int rd = Matrix[i][j];
            if (j + 1 < m)
                rd += dp[i - 1][j + 1];
            else
                rd += -1e5;

            dp[i][j] = max(up, max(ld, rd));
        }
    }

    for (int j = 0; j < m; j++)
    maxi = max(maxi, dp[n - 1][j]);

    cout << maxi;
    return 0;
}