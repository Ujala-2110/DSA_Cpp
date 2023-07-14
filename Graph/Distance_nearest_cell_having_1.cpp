// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1

#include<bits/stdc++.h>
using namespace std;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs( queue<pair<pair<int,int>,int>>&q, vector<vector<int>>&grid, vector<vector<int>>&vis
,vector<vector<int>>&mint)
{
    int n = grid.size();
    int m = grid[0].size();
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int lv = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0)
            {
                mint[nx][ny] = lv+1;
                q.push({{nx,ny},lv+1});
                vis[nx][ny] = 1;
            }
        }
    }
}

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>>mint(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q; //*************
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }
    
    bfs(q,grid,vis,mint);
    
    return mint;
}

//TC -> O(n*m)
//SC -> O(n*m)