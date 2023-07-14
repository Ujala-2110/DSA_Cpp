// Minimum Spanning Tree (MST) -> is only for connected graph
// In MST no cycle should be present
// It is like subgraph of the given graph
// There are two methods to find MST
// 1. -> Prim's algorithm
// 2. -> Kruskal's algorithm
//    ----> In kruskal's algorithm we sort the edges in increasing order according to the cost of edge and
//    we connect the edges keeping in mind that it should not form cycle by checking it by disjoint set. if
//    it will form a cycle we will not consider that edge otherwise we will coonect it.

#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int parent[10001];
int Rank[10001];

void make_set()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findPar(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findPar(parent[node]); //Path compression
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (Rank[u] < Rank[v])
        parent[u] = v;
    else if (Rank[v] < Rank[u])
        parent[v] = u;
    else
    {
        parent[u] = v;
        Rank[v]++;
    }
}

int main()
{
    make_set();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;  
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    //M*logM
    sort(edges.begin(), edges.end()); //It sorted according to the first element in default mode
    int cost = 0;

    //M x 4 x alpha x 2
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = findPar(u);
        int y = findPar(v);
        if (x == y) // To detect cycle
            continue;
        else
        {
            cout << u << " " << v << "\n";
            cost += w;
            Union(u, v);
        }
    }

    cout << cost << "\n";
    return 0;
}