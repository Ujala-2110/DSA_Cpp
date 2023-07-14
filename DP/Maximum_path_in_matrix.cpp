// Problem Statement

// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally
// below left or right. So from a particular cell (row, col), we can move in three directions i.e.
// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)

#include <bits/stdc++.h> 
using namespace std;

//Memoization
int func(int i,int j,int n,int m,vector<vector<int>>&triangle,vector<vector<int>>&dp)
{
    if(j < 0 || j >= m) return -1e9;
    if(i == n-1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    
    int down = triangle[i][j] + func(i+1,j,n,m,triangle,dp);
    int ldiag = triangle[i][j] + func(i+1,j-1,n,m,triangle,dp);
    int rdiag = triangle[i][j] + func(i+1,j+1,n,m,triangle,dp);
    
    return dp[i][j] = max({down,ldiag,rdiag});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<m;i++)
    {
        ans = max(ans , func(0,i,n,m,matrix,dp)); 
    }

    return ans;
}

//TC-> O(N*M) + O(M)
//SC -> O(N*M) + O(N)

// Tabulation
int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    int ans = INT_MIN;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<m;i++) dp[n-1][i] = triangle[n-1][i];

    for(int i=n-2;i>=0;i--)
    {
        for (int j = m-1; j >= 0; j--)
        {          
            int down = -1e8 , ldiag = -1e8 , rdiag = -1e8;
            down = triangle[i][j] + dp[i + 1][j];
            if(j-1 >= 0) ldiag = triangle[i][j] + dp[i + 1][j - 1];
            if(j+1 < m) rdiag = triangle[i][j] + dp[i + 1][j + 1];
            
            dp[i][j] = max({down,ldiag,rdiag});
        }
    }

    for(int i=0;i<m;i++) ans = max(ans,dp[0][i]);
    
    // return ans;
}

//TC-> O(N*M) + O(M)
//SC -> O(N*M)

//Space opptimization
int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    int ans = INT_MIN;
    vector<int>front(m+1,0) , curr(m+1,0);
    for(int i=0;i<m;i++) front[i] = triangle[n-1][i];

    for(int i=n-2;i>=0;i--)
    {
        for (int j = m-1; j >= 0; j--)
        {          
            int down = -1e8 , ldiag = -1e8 , rdiag = -1e8;
            down = triangle[i][j] + front[j];
            if(j-1 >= 0) ldiag = triangle[i][j] + front[j - 1];
            if(j+1 < m) rdiag = triangle[i][j] + front[j + 1];
            
            curr[j] = max({down,ldiag,rdiag});
        }
        front = curr;
    }

    for(int i=0;i<m;i++) ans = max(ans,front[i]);
    
    return ans;
}

//TC-> O(N*M) + O(M)
//SC -> O(M)


