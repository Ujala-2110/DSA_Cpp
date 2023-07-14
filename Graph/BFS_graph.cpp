#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> v;
        vector<int> vis(V, 0);

        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop(); 
            v.push_back(f);

            for (auto e : adj[f])
            {
                if (!vis[e])
                {
                    vis[e] = 1;
                    q.push(e);
                }
            }
        }
        return v;
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
    }

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}