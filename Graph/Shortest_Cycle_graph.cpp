// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
// A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

//1st method tried like longest graph but fails here
// 9
// [[4,5],[1,6],[6,4],[5,3],[3,6],[0,2],[5,8],[0,6],[3,0],[6,8],[2,8],[1,2]]

#include<bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void bfs(int src,vector<int> adj[],int n){
    vector<int> distance(n,(1e9));
    vector<int> parent(n, -1);
    
    queue<int> q;
    distance[src] = 0;
    q.push(src);

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();

        for (auto neigh : adj[node]) 
        {
            if (distance[neigh] == (int)(1e9)) 
            {
                distance[neigh] = 1 + distance[node];
                parent[neigh] = node;
                q.push(neigh);
            }
        
            else if (parent[node] != neigh && parent[neigh] != node)
                ans = min(ans, distance[neigh] + distance[node] + 1); //In case of bfs we move in different dirn so add
        }
    }
}

int findShortestCycle(int n, vector<vector<int>>& edges) {
    
    vector<int>adj[n+1];

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<n;i++)
    {
        bfs(i,adj,n);
    }
    if(ans == INT_MAX) return -1;
    return ans;
}

 
//Visited array (for personel understanding)

void bfs(int src,vector<int> adj[],int n){
    vector<int> distance(n,(1e9));
    vector<int> parent(n, -1);
    vector<int>vis(n,0);
    
    queue<int> q;
    distance[src] = 0;
    vis[src] = 1;
    q.push(src);

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();

        for (auto neigh : adj[node]) 
        {
            if (!vis[neigh]) 
            {
                distance[neigh] = 1 + distance[node];
                parent[neigh] = node;
                vis[neigh] = 1;
                q.push(neigh);
            }
        
            else if (parent[node] != neigh && parent[neigh] != node)
                ans = min(ans, distance[neigh] + distance[node] + 1);
        }
    }
}