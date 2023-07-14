#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, int x)
{
    vis[x] = 1;

    for (auto ch : adj[x])
        if (vis[ch] == 0)
            dfs(adj, vis, ch);
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // adj[v].push_back(u); //for directed graph
    }

    vector<int> vis(V + 10, 0);
    int ct = 0;

    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == 0){
          dfs(adj, vis, i);
            ct++;
        }
    }

    cout << ct << "\n";
    return 0;
}