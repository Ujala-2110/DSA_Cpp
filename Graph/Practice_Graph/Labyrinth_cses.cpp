#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[1001][1001];
bool vis[1001][1001];
char dir[1001][1001];
vector<char> path;

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;

    if (vis[x][y] == true || grid[x][y] == '#')
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (grid[a][b] == 'B')
        {
            while (1)
            {
                path.push_back(dir[a][b]);

                if (path.back() == 'L')
                    b++;
                if (path.back() == 'R')
                    b--;
                if (path.back() == 'U')
                    a++;
                if (path.back() == 'D')
                    a--;

                if (a == x && b == y)
                    break;
            }

            return true;
        }

        // left
        if (isValid(a, b - 1))
            dir[a][b - 1] = 'L', q.push({a, b - 1}), vis[a][b - 1] = true;
        // Right
        if (isValid(a, b + 1))
            dir[a][b + 1] = 'R', q.push({a, b + 1}), vis[a][b + 1] = true;
        // Up
        if (isValid(a - 1, b))
            dir[a - 1][b] = 'U', q.push({a - 1, b}), vis[a - 1][b] = true;
        // Down
        if (isValid(a + 1, b))
            dir[a + 1][b] = 'D', q.push({a + 1, b}), vis[a + 1][b] = true;
    }

    return false;
}

int main()
{
    cin >> N >> M;

    int x, y;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                x = i, y = j;
        }

    if (bfs(x, y) == true)
    {
        cout << "YES" << endl << path.size() << endl;
        while (path.size() > 0)
        cout << path.back(), path.pop_back();
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
