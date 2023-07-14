#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto ch : adj[node])
    {
        if (ch == par) continue;

        if (!vis[ch])
        {
            dfs(ch, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[ch]);
            if (low[ch] > tin[node])
                cout << node << " - " << ch << " is a bridge " << "\n";
        }

        else
            low[node] = min(low[node], tin[ch]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+10];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n+10, -1);
    vector<int> low(n+10, -1);
    vector<int> vis(n+10, 0);
    int timer = 0;
    for (int i = 1; i <=n; i++)
    {
        if (!vis[i])
            dfs(i, -1, vis, tin, low, timer, adj);
    }
    return 0;
}