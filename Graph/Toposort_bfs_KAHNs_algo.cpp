//we can also detect cycle using topological sort as cyclic graph donot give topological order
// it is also known as kahn's algorithm(Topological sort using bfs).

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n];
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }

    return 0;
}