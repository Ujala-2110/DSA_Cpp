#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> &leafs, vector<int> adj[])
{
  int deg = 0;
  for (int to : adj[node])
  {
    if (to != par)
    {
      deg++;
      dfs(to, node, leafs, adj);
    }
  }
  
  if (deg == 0)
  {
    leafs.push_back(node);
  }
}