#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int sz[100001];

void make_set(int N)
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findPar(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findPar(parent[node]); // Path compression
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    make_set(n);
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <=n ; i++)
        if (findPar(i) == i)
            cnt++;

    cout << cnt << "\n";
    return 0;
}