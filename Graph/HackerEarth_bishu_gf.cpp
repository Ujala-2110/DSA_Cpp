#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001];
int dist[100001];

void dfs(int node, int d)
{
    vis[node] = 1;
    dist[node] = d;
    for (auto ch : adj[node])
        if (vis[ch] == 0)
            dfs(ch, dist[node] + 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    int min_dist = INT_MAX, ans = -1;
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;

        if (dist[x] < min_dist)
        {
            min_dist = dist[x];
            ans = x;
        }
        else if (dist[x] == min_dist && x < ans)
            ans = x;
    }
    cout << ans;
    return 0;
}