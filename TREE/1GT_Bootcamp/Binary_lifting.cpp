#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//*********************************Binary Lifting**************************************************


void dfs(int current, vector<vector<int>>&edges, int parent, vector<int>&firstparent)
{
  firstparent[current] = parent;

  for(auto neigh : edges[current])
  {
    if(neigh != parent)  dfs(neigh,edges,current,firstparent);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<vector<int>>edges(n,vector<int>());

    for(int i=0;i<n-1;i++)
    {
      int u,v;
      cin>>u>>v;
      u--,v--;

      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    vector<vector<int>>parents(log2(n)+1 , vector<int>(n));

    // parents[log2(n)+1][n]
    // parents[k][i] -> 2 ^ kth parent of i

    // To calculate the first parent
    dfs(0,edges,-1,parents[0]);


    // magic parts

    for(int k=1;k<=log2(n);k++)
    {
      // Find the k^th parent of every node
      // Parent[k][i] -> 2 ^ kth parent of node i
      // Parent[k][i] -> 2 ^ (k-1)th parent of [2 ^ (k-1)th parent of i]

      for(int i=0;i<n;i++)
      {
        int intermediate = parents[k-1][i];

        // Parents[k][i] = parents[k-1][intermediate]

        if(intermediate != -1) parents[k][i] = parents[k-1][intermediate];

        else parents[k][i] = -1;
      }
    }

    //  i -> intermediate -> goal

    //  goal = 2 ^ kth parent of i
    //  goal = 2 ^ (k-1)th parents of intermediate
    //  intermediate = 2 ^ (k-1)th parent of i

  }

  return 0;
}


// **************************** To find Kth parent of x ******************************************************

int KthParent(int x, int k, vector<vector<int>>&parents)
{
  int n = parents[0].size();

  for(int i = 0; i <= log2(n); i++)
  {
    if(k & (1 << i))
    {
      x = parents[i][x];
      if(x == -1) break;
    }
  }

  return x;
}