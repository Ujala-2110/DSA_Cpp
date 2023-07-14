#include <bits/stdc++.h>
using namespace std;
int parent[10001];
int sz[10001];
multiset<int> sizes;

void make_set(int N)
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        sz[i] = 1;
        sizes.insert(1);
    }
}

int find_par(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = find_par(parent[node]);
}

void merge(int u, int v)
{
    sizes.erase(sizes.find(sz[u]));
    sizes.erase(sizes.find(sz[v]));

    sizes.insert(sz[u] + sz[v]);
}

void Union(int u, int v)
{
    u = find_par(u);
    v = find_par(v);

    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        merge(u, v);
        sz[u] += sz[v];
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    make_set(n);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        Union(a, b);

        if (sizes.size() == 1)
            cout << 0 << endl;

        else
        {
            int mx = *(sizes.begin()); // First element in multiset
            int mn = *(--sizes.end()); // Last element in multiset

            cout << mx - mn << endl;
        }
    }

    return 0;
}