#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100001];
int vis[10001], tin[10001], low[10001];
set<int> AP;
int timer;

void dfs(int node, int par)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int ch_cnt = 0;

    for (int ch : adj[node])
    {
        if (ch == par) continue;
        if (!vis[ch])
        {
            dfs(ch, node);
            ch_cnt++;
            low[node] = min(low[node], low[ch]);

            if (tin[node] <= low[ch] && par != -1) AP.insert(node);
        }

        else low[node] = min(low[node], tin[ch]);
    }

    if (par == -1 && ch_cnt > 1) AP.insert(node);
}

int main()
{
    ll n, m, u, v;

    while (1)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++)
            adj[i].clear(), vis[i] = 0;
        AP.clear();
        timer = 1;

        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
                dfs(i, -1);
        }
        cout << AP.size() << "\n";
    }

    return 0;
}