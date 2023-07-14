// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3
// Explanation:
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
// The highlighted cells represents the land cells.

#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, vector<vector<int>>&image)
{
    int n = image.size();
    int m = image[0].size();
    
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    return true;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x,int y, vector<vector<int>>&mat,vector<vector<int>>&vis)
{
    vis[x][y] = 1;
    
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(is_valid(nx,ny,mat) && vis[nx][ny] == 0 && mat[nx][ny] == 1)
        {
            dfs(nx,ny,mat,vis);
        }
    }
}


int numberOfEnclaves(vector<vector<int>> &mat) {
    
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    for(int j=0;j<m;j++){
        if(vis[0][j] == 0 && mat[0][j] == 1) dfs(0,j,mat,vis);
    }
    
    for(int j=0;j<m;j++){
        if(vis[n-1][j] == 0 && mat[n-1][j] == 1) dfs(n-1,j,mat,vis);
    }
    
    for(int i=0;i<n;i++){
        if(vis[i][0] == 0 && mat[i][0] == 1) dfs(i,0,mat,vis);
    }
    
    for(int i=0;i<n;i++){
        if(vis[i][m-1] == 0 && mat[i][m-1] == 1) dfs(i,m-1,mat,vis);
    }
    
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && mat[i][j] == 1) ans++;
        }
    }
    
    return ans;
}

//TC -> O(n*m)
//SC -> O(n*m)


    