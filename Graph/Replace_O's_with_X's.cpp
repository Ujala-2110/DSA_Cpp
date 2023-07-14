// Given a matrix mat of size N x M where every element is either O or X.
// Replace all O with X that are surrounded by X.
// A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, vector<vector<char>>&image)
{
    int n = image.size();
    int m = image[0].size();
    
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    return true;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x,int y, vector<vector<char>>&mat,vector<vector<int>>&vis)
{
    vis[x][y] = 1;
    
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(is_valid(nx,ny,mat) && vis[nx][ny] == 0 && mat[nx][ny] == 'O')
        {
            dfs(nx,ny,mat,vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        if(vis[0][j] == 0 && mat[0][j] == 'O') dfs(0,j,mat,vis);
    }
    
    for(int j=0;j<m;j++){
        if(vis[n-1][j] == 0 && mat[n-1][j] == 'O') dfs(n-1,j,mat,vis);
    }
    
    for(int i=0;i<n;i++){
        if(vis[i][0] == 0 && mat[i][0] == 'O') dfs(i,0,mat,vis);
    }
    
    for(int i=0;i<n;i++){
        if(vis[i][m-1] == 0 && mat[i][m-1] == 'O') dfs(i,m-1,mat,vis);
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
        }
    }
    
    return mat;
}

//TC -> O(n*m)
//SC -> O(n*m)

// Notice carefully that the set of 'O' s connected to any edge cannot be transformed to 'X'.