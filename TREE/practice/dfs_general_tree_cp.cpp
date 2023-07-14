// You're given a tree with N vertices numbered from 1 to N. A tree is defined as a connected, undirected graph with N vertices and N−1 edges. The distance between two vertices in a tree is equal to the number of edges on the unique simple path between them.
// The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define mod 1000000007

void dfs(int v, vector<int> &depth, vector<int> g[], int par = -1)
{
    for (auto ch : g[v])
    {
        if (ch == par)
            continue;
        depth[ch] = depth[v] + 1;
        dfs(ch, depth, g, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    // for (int tt = 1; tt <= t; tt++)
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> g[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> depth(n + 1, 0);
        dfs(1, depth, g);

        int mx_depth = -1;
        int mx_node;

        for (int i = 1; i <= n; i++)
        {
            if (mx_depth < depth[i])
            {
                mx_depth = depth[i];
                mx_node = i;
            }

            depth[i] = 0;
        }

        dfs(mx_node, depth, g);
        int ans = -1;

        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, depth[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}
