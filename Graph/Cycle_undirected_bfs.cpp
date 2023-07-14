#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph.

bool bfs(int x, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;

    vis[x] = 1;
    q.push({x, -1});

    while (!q.empty())
    {
        int node = (q.front()).first;
        int par = (q.front()).second;
        q.pop();

        for (auto e : adj[node])
        {
            if (!vis[e])
            {
                vis[e] = 1;
                q.push({e, node});
            }
            else if (par != e) return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (vis[i]) continue;
        if (bfs(i, adj, vis)) return true;
    }
    return false;
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
    }

    bool ans = isCycle(V, adj);
    if (ans)
        cout << "Cycle is present\n";
    else
        cout << "Cycle is not present\n";

    return 0;
}
