#include <bits/stdc++.h>
using namespace std;
// int dp[205][205];

// Recursion
/*
int minSumPath(int m, int n, int i,int j,vector<vector<int>> &A)
{
    if (i == m - 1) return A[i][j];

    int down = A[i][j] + minSumPath(m, n, i + 1, j, A);
    int dg = A[i][j] + minSumPath(m, n, i + 1, j + 1, A);

    return min(down, dg);
}
*/

// Memoization
/*
int minSumPath(int m, int n, int i,int j,vector<vector<int>> &A)
{
    if (i == m - 1) return A[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = A[i][j] + minSumPath(m, n, i + 1, j, A);
    int dg = A[i][j] + minSumPath(m, n, i + 1, j + 1, A);

    return dp[i][j] = min(down, dg);
}
*/

// Tabulation
int minSumPath(int m, int n, vector<vector<int>> &A)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[m - 1][i] = A[m - 1][i];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = A[i][j] + dp[i + 1][j];
            int dg = A[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, dg);
        }
    }

    return dp[0][0];

    // 2
    // 3 4
    // 6 5 7
    // 4 1 8 3 //(n-1)th row
}

// Space Optimization
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.

    //vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<int> prev(n, 0), cur(n, 0);
    for (int i = 0; i < n; i++) prev[i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int diag = triangle[i][j] + prev[j + 1];

            cur[j] = min(down, diag);
        }

        prev = cur;
    }

    return prev[0];
}

int main()
{
    vector<vector<int>> A{{2}, {5, 9}, {1, 6, 7}};
    int m = A.size();
    int n = A[0].size();
    // memset(dp,-1,sizeof(dp));
    cout << minSumPath(m, n, A); // Tabulation
    return 0;
}