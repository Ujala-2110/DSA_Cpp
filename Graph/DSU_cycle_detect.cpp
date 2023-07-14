#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
int parent[10001];
int Rank[10001];

void make_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findPar(int node)
{
    if (node == parent[node]) return node;

    return parent[node] = findPar(parent[node]); //Path compression
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (Rank[u] < Rank[v]) parent[u] = v;
    else if (Rank[v] < Rank[u]) parent[v] = u;
    else // if(parent[u] == parent[v])
    {
        parent[u] = v;
        Rank[v]++;
    }
}

int main()
{
    int n;
    cin >> n;
    make_set(n);
    while (n--)
    {
       int u,v;
       cin>>u>>v;
       Union(u,v);
    }
    
    //If 2 and 3 belong to the same set or not
    if(findPar(2) != findPar(3))
    cout<<"Belong to different set";
    else
    cout<<"Belong to same set";
}