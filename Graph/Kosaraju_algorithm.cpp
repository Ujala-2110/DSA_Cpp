// Kosaraju's algorithm --> valid for directed graph only
// It is used for counting the number of strongly connected components(SCC) in DAG
// Strongly connected components means there is a path present from any node to other node
// In strongly connected component if it contain more than 2 elements then it contain cycle
// Three steps involved in it
// 1-> sort all nodes in order of finishing time (for this use Topological sort)
// 2-> Transpose the graph (So that you don't go to other parts) --> all the edges gets reversed
// 3-> Do the dfs according to the finishing time

#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (vis[it] == 0)
            dfs(it, adj, vis, st);
    }

    st.push(src);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
        if (vis[it] == 0)
            revDfs(it, vis, transpose);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> vis(n, 0);

    // step 1-> Topo sort
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs(i, adj, vis, st);
    }

    // step 1-> Transpose
    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0; // while doing previous dfs we have marked all node as visited that's why we have unvisited it again for next dfs
        for (auto it : adj[i])
            transpose[it].push_back(i); // for transpose
    }

    // step 3-> revDfs
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (vis[node] == 0)
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << "\n";
        }
    }
}