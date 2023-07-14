#include<bits/stdc++.h>
using namespace std;

// Method->1

int dfs(int currentNode, vector<int> adj[], int parent)
{
  int lvl = 0;
  for (int neighbour : adj[currentNode])
  {
    if (neighbour != parent)
    {
      lvl = max(lvl , dfs(neighbour, adj, currentNode));
    }
  }

  return lvl+1;
}

//Method->2

void dfs(int currentNode, vector<int> adj[], int parent, vector<int> &level, int currentLevel)
{
  level[currentNode] = currentLevel;
  for (int neighbour : adj[currentNode])
  {
    if (neighbour != parent)
    {
      dfs(neighbour, adj, currentNode, level, currentLevel + 1);
    }
  }
}