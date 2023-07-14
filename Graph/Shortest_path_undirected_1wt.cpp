// You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
    
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n,INF);
    
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node])
        {
            if(1 + dist[node] < dist[it])
            {
                q.push(it);
                dist[it] = dist[node] + 1;
            }
        }
    }
    
    for(int i=0;i<n;i++) if(dist[i] == INF) dist[i] = -1;
    return dist;
    
}

//TC->O(N+M)
//SC->O(N+M)