// Problem Statement

// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, 'C' - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j − 1) or (i + 1, j + 1). They will always stay inside the 'GRID'.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
// -----> We have to start from (0,0) and (0,c-1) and end to any row and maximize the overall score


#include <bits/stdc++.h> 
using namespace std;

//Memoization
int func(int i,int j1, int j2, int r ,int c, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
{
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;
    
    if(i == r-1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = INT_MIN;
    for(int dj1 = -1 ; dj1 <= +1 ; dj1++)
    {
        for(int dj2 = -1 ; dj2 <= +1 ; dj2++)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += func(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi = max(maxi , value);
        }
    }
    
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return func(0,0,c-1,r,c,grid,dp);
}


//Tabulation

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));
    
    for(int j1=0;j1<c;j1++)
    {
        for(int j2=0;j2<c;j2++)
        {
            if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j1=c-1;j1>=0;j1--)
        {
           for(int j2=c-1;j2>=0;j2--)
           {
               int maxi = INT_MIN;
               for(int dj1 = -1 ; dj1 <= +1 ; dj1++)
               {
                   for(int dj2 = -1 ; dj2 <= +1 ; dj2++)
                   {
                       int value = 0;
                       if(j1 == j2) value = grid[i][j1];
                       else value = grid[i][j1] + grid[i][j2];
                       
                       if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                       value += dp[i+1][j1+dj1][j2+dj2];
                       else value += -1e8;
                       
                       maxi = max(maxi , value);
                       dp[i][j1][j2] = maxi;
                   }
               }
           }
        }
    }
    
    return dp[0][0][c-1];
}


//Space Optimization
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<int>>prev(c,vector<int>(c,0));
    vector<vector<int>>curr(c,vector<int>(c,0));
    
    for(int j1=0;j1<c;j1++)
    {
        for(int j2=0;j2<c;j2++)
        {
            if(j1 == j2) prev[j1][j2] = grid[r-1][j1];
            else prev[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j1=c-1;j1>=0;j1--)
        {
           for(int j2=c-1;j2>=0;j2--)
           {
               int maxi = INT_MIN;
               for(int dj1 = -1 ; dj1 <= +1 ; dj1++)
               {
                   for(int dj2 = -1 ; dj2 <= +1 ; dj2++)
                   {
                       int value = 0;
                       if(j1 == j2) value = grid[i][j1];
                       else value = grid[i][j1] + grid[i][j2];
                       
                       if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                       value += prev[j1+dj1][j2+dj2];
                       else value += -1e8;
                       
                       maxi = max(maxi , value);
                       curr[j1][j2] = maxi;
                   }
               }
           }
        }
        prev = curr;
    }
    
    return prev[0][c-1];
}
