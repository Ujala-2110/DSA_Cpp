// Eulerian Path is a path in graph that visits every edge exactly once. 
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

// Eulerian Cycle 
// An undirected graph has Eulerian cycle if following two conditions are true. 
// ….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges). 
// ….b) All vertices have even degree.

// Eulerian Path 
// An undirected graph has Eulerian Path if following two conditions are true. 
// ….a) Same as condition (a) for Eulerian Cycle 
// ….b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)
// Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

#include <bits/stdc++.h>
using namespace std;

int eulerPath(int N, vector<vector<int>> graph)
{
    // code here
    int odd = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < graph[0].size(); j++)
        {
          if (graph[i][j] == 1)  count++; //degree of an node for a particular i. suppose i=1 and j=2 (graph[i][j] == 1) that means there is an edge between 1 and 2. 
            
        }
        if (count & 1) odd++; // Number of node whose degree is odd. (If zero or two vertices have odd degree and all other vertices have even degree)
    }
    if (odd == 0 || odd == 2) return 1;
    else return 0;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }

    cout << eulerPath(N, graph);
    return 0;
}