#include <bits/stdc++.h>
using namespace std;

int N;
char grid[31][31];
int vis[31][31];
int dist[31][31];

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > N)
        return false;

    if (vis[x][y] == true || grid[x][y]=='T')
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(char srcX, char srcY)
{
    queue<pair<int, int>> q;
    vis[srcX][srcY] = 1;
    dist[srcX][srcY] = 0;
    q.push({srcX, srcY});
    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
            if (isValid(currX + dx[i], currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                dist[newX][newY] = dist[currX][currY] + 1;
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
    }
}

int main()
{
    int srcX,srcY,endX,endY;
    cin >> N;
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      cin>>grid[i][j];
      if(grid[i][j]== 'S') 
      srcX = i, srcY = j;
      if(grid[i][j]== 'E') 
      endX = i, endY = j;
    }
    bfs(srcX,srcY);
    cout<<dist[endX][endY]<<"\n";

    return 0;
}