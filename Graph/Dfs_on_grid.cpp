#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] == true)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    vis[x][y] = 1;
    cout << x << " " << y << "\n";

    for (int i = 0; i < 4; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);

    // if (isValid(x - 1, y)) //up
    //     dfs(x - 1, y);

    // if (isValid(x, y + 1)) //right
    //     dfs(x, y + 1);

    // if (isValid(x + 1, y)) //down
    //     dfs(x + 1, y);

    // if (isValid(x, y - 1)) //left
    //     dfs(x, y - 1);
}

int main()
{
    cin >> n >> m;
    dfs(1, 1); //Initial cell
    return 0;

    // cell ->node
    // sides->edges
    
}