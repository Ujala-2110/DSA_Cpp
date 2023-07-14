#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
int uniquePathsWithObstacles(vector<vector<int>>&grid,int m ,int n)
{
    if(m>=0 && n>=0 && grid[m][n] == 1) return 0;
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;

    return uniquePathsWithObstacles(grid,m-1,n) + uniquePathsWithObstacles(grid,m,n-1);
}
*/

//Recursion
/*
int uniquePathsWithObstacles(vector<vector<int>>&grid,int m ,int n,vector<vector<int>>&dp)
{
    if(m>=0 && n>=0 && grid[m][n] == 1) return 0;
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    return dp[m][n] = uniquePathsWithObstacles(grid,m-1,n,dp) + uniquePathsWithObstacles(grid,m,n-1,dp);
}
*/

int uniquePathsWithObstacles(vector<vector<int>> &grid, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (grid[i][j] == 1)  dp[i][j] = 0;
            else if (i == 0 && j == 0)  dp[i][j] = 1;

            else
            {
                int up = 0;
                int left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m][n];
}

int main()
{  
    vector<vector<int>> A = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int m = A.size(); //row
    int n = A[0].size(); //column
    // cout<<m<<" "<<n;
    cout << uniquePathsWithObstacles(A, m - 1, n - 1) << "\n"; // Recursion and Tabulation
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout << uniquePathsWithObstacles(A,m-1,n-1,dp) << "\n"; //Memoization

    return 0;
}