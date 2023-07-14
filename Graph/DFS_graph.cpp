#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(vector<int> adj[], vector<int> &ans, int x, int vis[])
    {
        ans.push_back(x);
        vis[x] = 1;

        for (int i : adj[x])
            if (vis[i] == 0)
                dfs(adj, ans, i, vis);
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        int vis[V];

        for (int i = 0; i < V; i++)
            vis[i] = 0;

        for (int i = 0; i < V; i++)
            if (vis[i] == 0)
                dfs(adj, ans, i, vis);

        return ans;
    }
};

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

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
