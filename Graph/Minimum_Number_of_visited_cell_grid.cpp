#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y,vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    return true;
}

int minimumVisitedCells(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},0});
    dist[0][0] = 0;

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int lvl = q.front().second;
        q.pop();


        if(x == n-1 && y == n-1) return lvl;

        for(int k = y+1; k <= grid[x][y]+y; k++)
        {
            if(is_valid(x,k,grid) && vis[x][k] == 0)
            {
                vis[x][k] = 1;
                q.push({{x,k},lvl+1});
            }
        }

        for(int k = x+1; k <= grid[x][y]+x; k++)
        {
            if(is_valid(k,y,grid) && vis[k][y] == 0)
            {
                vis[k][y] = 1;
                q.push({{k,y},lvl+1});
            }
        }
    }

    return -1;
}
