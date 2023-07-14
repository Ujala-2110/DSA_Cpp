#include <bits/stdc++.h>
using namespace std;

    // Function to detect cycle in an undirected graph.

    bool dfs(int x, int par, vector<int> adj[], vector<int> &vis)
    {
        vis[x] = 1;
        bool isLoop = false;
        for (auto ch : adj[x])
        {
            if (vis[ch] && par == ch) continue;
            if (vis[ch]) return true;

            isLoop |= dfs(ch, x, adj, vis);
        }

        return isLoop;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (vis[i]) continue;
            if (dfs(i, -1, adj, vis)) return true;
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
        // adj[v].push_back(u); //for directed graph
    }

    bool ans = isCycle(V, adj);
    if (ans)
        cout << "Cycle is present\n";
    else
        cout << "Cycle is not present\n";

    return 0;
}


//Using bfs
bool bfs(int x,vector<int>adj[], vector<int>&vis,int V)
{
    queue<pair<int,int>>q;
    q.push({x,-1});
    vis[x] = 1;
    
    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                q.push({it,node});
                vis[it] = 1;
            }
            
            else if(it != par) return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<int>vis(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i] == 0)
        {
            if(bfs(i,adj,vis,V)) return true;
        }
    }
    
    return false;
}