// cses

#include <bits/stdc++.h>
using namespace std;

const int LOG = 21; 
const int MAXARR = 2e5 + 5;
vector<vector<int>> adj(MAXARR);
int depth[MAXARR];
vector<vector<int>> up(MAXARR, vector<int>(LOG + 5));


void dfs(int u, int p)
{
  for (auto v : adj[u])
  {
    if (v == p) continue;

    depth[v] = depth[u] + 1;

    up[v][0] = u;
    
    for (int i = 1; i <= LOG; i++)
    {
      up[v][i] = up[up[v][i - 1]][i - 1];
    }

    dfs(v, u);
  }
}

int getLca(int u, int v)
{
    if (depth[u] < depth[v])
    {
      swap(u, v);
    }

    int k = depth[u] - depth[v];

    for (int j = LOG; j >= 0; j--)
    {
      if ((k & (1 << j)))
      {
        u = up[u][j];
      }
    }

    if (u == v) return u;

    for (int j = LOG; j >= 0; j--)
    {
      if (up[u][j] != up[v][j])
      {
        u = up[u][j];
        v = up[v][j];
      }
    }
    
    return up[u][0];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i < n; i++)
  {
    int a,b;
    cin>>a>>b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0); // consider 1 as a root (change accordingly)

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;

    int lca = getLca(a, b);

    int ans = depth[a] + depth[b] - 2 * depth[lca];

    cout<<ans<<"\n";
  }
  
  return 0;
}

