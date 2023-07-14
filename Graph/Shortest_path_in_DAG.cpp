#include <bits/stdc++.h>
using namespace std;

void FindToposort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
            FindToposort(it.first, vis, st, adj);
    }
    st.push(node);
}

void shortest_path(int src, int n, vector<pair<int, int>> adj[])
{
    int vis[n] = {0};
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        FindToposort(i, vis, st, adj);
    }

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = 1e5;

    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != 1e5)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }
    }

    for (int i = 0; i < n; i++)
        (dist[i] == 1e5) ? cout << "INF " : cout << dist[i] << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    shortest_path(0, n, adj);
    return 0;
}