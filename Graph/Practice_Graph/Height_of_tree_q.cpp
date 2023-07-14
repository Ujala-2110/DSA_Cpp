#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &height)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            height[it] = height[node] + 1;
            dfs(it, adj, vis, height);
        }
    }
}

int optimalValue(int n, int x, vector<int> &p)
{
    //Formation of tree
    vector<int> adj[n + 1];
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1) root = i + 1;
        else adj[p[i]].push_back(i + 1);
    }

    vector<int> vis(n + 1, 0);
    vector<int> height(n + 1, 0);

    height[root] = 1;
    dfs(root, adj, vis, height); //calculating height

    int depth = *max_element(height.begin(), height.end()); 
    return (x + (depth - 1)) / depth; //Result is ceil of x/depth . we wiil give equal value at all level so ans will be
 // depth * a(value at each level) = x. a => x/depth
}

int main()
{
    int N = 4, X = 7;
    vector<int> p = {-1, 1, 2, 3};

    int ans = optimalValue(N, X, p);
    cout << ans << "\n";
}