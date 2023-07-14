#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
int minCost(vector<vector<int>> &cost, int m, int n)
{
    if (m == 0 && n == 0) return cost[0][0];
    if (m < 0 || n < 0) return 1e5;

    int up = cost[m][n] + minCost(cost, m - 1, n);
    int left = cost[m][n] + minCost(cost, m, n - 1);

    return min(up, left);
}
*/

//Memoization
/*
int minCost(vector<vector<int>> &cost, int m, int n,vector<vector<int>>&dp)
{
    if (m == 0 && n == 0) return cost[0][0];
    if (m < 0 || n < 0) return 1e5;

    if(dp[m][n] != -1) return dp[m][n];

    int up = cost[m][n] + minCost(cost, m - 1, n,dp);
    int left = cost[m][n] + minCost(cost, m, n - 1,dp);

    return dp[m][n] =  min(up, left);
}
*/

//Tabulation
int minCost(vector<vector<int>> &cost, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0) dp[i][j] = cost[i][j];
            else
            {
                int up = cost[i][j];
                if (i > 0)  up += dp[i - 1][j];
                else
                    up += 1e5;

                int left = cost[i][j];
                if (j > 0) left += dp[i][j - 1];
                else
                    left += 1e5;

                dp[i][j] = min(up, left);
            }
        }

    }

    return dp[m][n];
}

//Space Optimization
int minPathSum(vector<vector<int>>& grid) {
    // memset(dp,-1,sizeof(dp));
    int n = grid.size();
    int m = grid[0].size();

    // vector<vector<int>>dp(n,vector<int>(m,0)); 

    // dp[0][0] = grid[0][0];
    // for(int i=1;i<n;i++) dp[i][0] = grid[i][0] + dp[i-1][0];
    // for(int i=1;i<m;i++) dp[0][i] = grid[0][i] + dp[0][i-1];

    vector<int>prev(m+1,0);
    for(int i=0;i<n;i++)
    {
        vector<int>curr(m+1,0);
        for(int j=0;j<m;j++)
        {
            if(i == 0 && j == 0) {
                curr[j] = grid[0][0];
                continue;
            }
            
            int up = 1e5 , left = 1e5;
            if(i-1 >= 0) up = grid[i][j] + prev[j];
            if(j-1>=0) left = grid[i][j] + curr[j-1];
            
            curr[j] = min(up,left);
        }
        prev = curr;
    }

    return prev[m-1];
}

int main()
{
    vector<vector<int>> cost = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    int m = cost.size();
    int n = cost[0].size();
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout << "  " << minCost(cost, m - 1, n - 1,dp);
    cout << "  " << minCost(cost, m - 1, n - 1);
    return 0;
}