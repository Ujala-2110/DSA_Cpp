#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001];
int dist[100001];

void bfs(int src)
{
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto e : adj[f])
        {
            if (!vis[e])
            {
                dist[e] = dist[f] + 1;
                vis[e] = 1;
                q.push(e);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(1);
        cout << dist[n] << "\n";
    }
    return 0;
}