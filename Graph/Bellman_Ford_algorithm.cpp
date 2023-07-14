// It is not valid for negative weight cycle

// It is used to find shortest path in graph and check to negative weight cycle in the graph.

// Dijkstra doesn’t work for Graphs with negative weights, Bellman-Ford works for such graphs. 
// Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
// But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

// I am considring Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    // int src;
    // cin >> src;

    int inf = 1e5;
    vector<int> dist(n, inf);
    dist[0] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it[0]] + it[2] < dist[it[1]])
                dist[it[1]] = dist[it[0]] + it[2];
        }
    }

    bool flag = false;

    for (auto it : edges)
    {
        if (dist[it[0]] + it[2] < dist[it[1]])
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    cout<<"It contains negative cycle";
    else
    cout<<"It does not contains negative cycle";

    return 0;
}