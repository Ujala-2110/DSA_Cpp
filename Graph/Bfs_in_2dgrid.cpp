#include <bits/stdc++.h>
using namespace std;

int N, M;
int dist[1001][1001];
int vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;
    if (vis[x][y] == 1)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
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

    cout << "Distance array\n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << dist[i][j] << " ";

        cout << "\n";
    }
}

int main()
{
    int x, y;
    cin >> N >> M;
    cin >> x >> y;
    bfs(x, y);
    return 0;
}

class Dsu
{
public:
    vector<int> parent, size;
    Dsu(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int a)
    {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void uni(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] > size[b])
            {
                parent[b] = a;
                size[a] += size[b];
            }
            else
            {
                parent[a] = b;
                size[b] += size[a];
            }
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &s)
    {
        int n = s.size();
        Dsu a(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else
                {
                    if (s[j][0] == s[i][0] || s[j][1] == s[i][1])
                    {
                        a.uni(i, j);
                    }
                }
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (a.parent[i] == i)
            {
                total++;
            }
        }
        return n - total;
    }
};