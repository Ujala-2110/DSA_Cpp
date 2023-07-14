// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

// Example:

// Input:
// n = 6, m= 7
// edge=[[0,1,2],[0,4,1],[4,5,4]
// ,[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

// Output:
// 0 2 3 6 1 5

// It can be solved by Dijkstra also

// Processing the vertices in topological order ensures that by the time u get to a vertex, you have already processed
// all the vertices that precede it

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void TopoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
            TopoSort(v, adj, vis, st);
    }

    st.push(node);
}

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];

    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> vis(n, 0);
    stack<int> st;

    //O(n+m)
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) TopoSort(i, adj, vis, st);
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    //O(n+m)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int i = 0; i < n; i++) if (dist[i] == INF) dist[i] = -1;
    return dist;
}

//TC -> O(n+m)
//SC -> O(n+m)