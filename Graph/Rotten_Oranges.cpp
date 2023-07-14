// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

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
    
int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,queue<pair<pair<int,int>,int>>&q
,int &cnt)
{
    int res = INT_MIN;
    
    while(!q.empty())
    {
        int x = (q.front().first).first;
        int y = (q.front().first).second;
        int lv = q.front().second;
        q.pop();
            
        res = max(res,lv);
            
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if(is_valid(nx,ny,grid) && vis[nx][ny] == 0 && grid[nx][ny] == 1)
            {
                q.push({{nx,ny},lv+1});
                vis[nx][ny] = 1;
                cnt++;
            }
        }
    }
        
    return res;
}

int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    int cnt_1 = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q; //***********

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 2 && vis[i][j] == 0)
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            
            if(grid[i][j] == 1) cnt_1++;
        }
    }
    
    int cnt = 0;
    int max_ans = bfs(grid,vis,q,cnt);
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(grid[i][j] == 1 && vis[i][j] == 0)
    //         return -1;
    //     }
    // }
    
    if(cnt_1 != cnt) return -1;
    
    return max_ans;
}