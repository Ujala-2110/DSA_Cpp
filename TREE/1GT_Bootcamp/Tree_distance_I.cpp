// You are given a tree consisting of n nodes.
// Your task is to determine for each node the maximum distance to another node.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int> &dist)
{
  for (auto ch : adj[node])
  {
    if (ch == par) continue;

    dist[ch] = dist[node] + 1;
    dfs(ch, node, adj, dist);
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> adj[n + 1];

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> depth(n + 1, 0);
  dfs(1, -1, adj, depth); // Any arbitrary point

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

  dfs(mx_node, -1, adj, depth); //One end point of diameter

  int mx_depth1 = -1;
  int mx_node1;

  vector<int>distances(n+1,0);
  for (int i = 1; i <= n; i++)
  {
    distances[i] = max(depth[i], distances[i]);
    if(depth[i] > mx_depth1)
    {
      mx_depth1 = depth[i];
      mx_node1 = i;
    }

    depth[i] = 0;
  }

  dfs(mx_node1,-1,adj,depth); //Other end point of diameter

  for (int i = 1; i <= n; i++)
  {
    distances[i] = max(depth[i], distances[i]);
  }

  for(int i=1;i<=n;i++) cout<<distances[i]<<" ";

  return 0;
}