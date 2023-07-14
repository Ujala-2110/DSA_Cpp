#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph using (DFS).



//Using visited and pathvisited array 
bool dfs(int x,int n,vector<int>adj[],vector<int>&vis ,vector<int>&pathvis)
{
    vis[x] = 1;
    pathvis[x] = 1;
    
    for(auto it : adj[x])
    {
        if(vis[it] == 0)
        {
            if(dfs(it,n,adj,vis,pathvis)) return true;
        }
        
        else if(pathvis[it]) return true;
    }
    
    pathvis[x] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {

    vector<int>vis(V,0);
    vector<int>pathvis(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(dfs(i,V,adj,vis,pathvis)) return true;
    }
    
    return false;
}


//Using pair in visited array to store vis in first place and pathvis in second place

bool dfs(int x,int n,vector<int>adj[],vector<pair<int,int>>&vis)
{
    vis[x] = {1,1};
    
    for(auto it : adj[x])
    {
        if(vis[it].first == 0)
        {
            if(dfs(it,n,adj,vis)) return true;
        }
        
        else if(vis[it].second) return true;
    }
    
    vis[x].second = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {

    vector<pair<int,int>>vis(V,{0,0});
    
    for(int i=0;i<V;i++)
    {
        if(dfs(i,V,adj,vis)) return true;
    }
    
    return false;
}

//Using only visited array
    // 0 -> unvisited
    // 1 -> visited
    // 2 -> pathvisited and visited



bool dfs(int x,int n,vector<int>adj[],vector<int>&vis)
{
    vis[x] = 2;
    
    for(auto it : adj[x])
    {
        if(vis[it] == 0)
        {
            if(dfs(it,n,adj,vis)) return true;
        }
        
        else if(vis[it] == 2) return true;
    }
    
    vis[x] = 1;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
        
    vector<int>vis(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(dfs(i,V,adj,vis)) return true;
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
        adj[u].push_back(v); //for directed graph
    }

    bool ans = isCyclic(V, adj);
    if (ans)
        cout << "Cycle is present\n";
    else
        cout << "Cycle is not present\n";

    return 0;
}
