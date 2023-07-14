// Topological sort is possible only in DAG (Directed Acyclic Graph)
// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u  v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

// Difference between Topological sort and DFS
// In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack.

// Firstly node's childs are pushed into stack and then node itself, such that node will pop out first and then it's child.
// Topological sort is increasing order of indegree of node [0->1->2->3->4->5.. ] like that.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto ch : adj[node])
    {
        if (vis[ch] == 0)
            dfs(ch, adj, vis, st);
    }
    st.push(node);
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs(i, adj, vis, st);
    }
    // we need to check it before printing whether it is topo sort or not see in gfg(practice).
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}