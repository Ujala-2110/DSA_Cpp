#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];
int vis[1005][1005];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] == true || grid[x][y] == 0)
        return false;

    return true;
}

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    vis[srcX][srcY] = 1;
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
            vis[newX][newY] = 1;
            q.push({newX, newY});
        }
    }
}

// void dfs(int x, int y)
// {
//     vis[x][y] = 1;

//     for (int i = 0; i < 4; i++)
//     {
//         if (isValid(x + dx[i], y + dy[i]))
//         dfs(x + dx[i], y + dy[i]);
//     }
// }

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '#')
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                bfs(i, j);
                // dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}