#include <bits/stdc++.h>
using namespace std;

const int LOG = 21; // change accordingly
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

  for (int i = 2; i <= n; i++)
  {
    int x;
    cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  dfs(1, 0); // consider 1 as a root (change accordingly)

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;

    int lca = getLca(a, b);

    cout << lca << "\n";
  }
  
  return 0;
}

//////******************************************//////////////////
// const int MAXARR = 2e5 + 5;
// const int LOGMAXARR = 20;

// vector<int> ss[MAXARR];
// int depth[MAXARR];
// int parents[MAXARR][LOGMAXARR];

// int lca(int a, int b)
// {
//   if (depth[a] > depth[b])
//     swap(a, b);

//   int diff = depth[b] - depth[a];
//   for (int i = 0; i < LOGMAXARR; i++)
//     if (diff & (1 << i))
//       b = parents[b][i];

//   if (a == b)
//     return a;

//   for (int i = LOGMAXARR - 1; i >= 0; i--)
//     if (parents[b][i] != parents[a][i])
//       b = parents[b][i], a = parents[a][i];

//   return parents[a][0];
// }

// void dfs(int node, int parent, int r)
// {
//   depth[node] = r;
//   parents[node][0] = parent;
//   int cur = parent;

//   for (int i = 1; i < LOGMAXARR && (1 << i) <= r; i++) //****************//
//   {
//     parents[node][i] = parents[cur][i - 1];
//     cur = parents[cur][i - 1];
//   }

//   for (auto child : ss[node])
//     if (child != parent)
//       dfs(child, node, r + 1);
// }

// void solve()
// {
//   int n, q, a, b;
//   cin >> n >> q;

//   for (int i = 1; i < n; i++)
//   {
//     cin >> a;
//     ss[a - 1].push_back(i);
//     ss[i].push_back(a - 1);
//   }

//   dfs(0, -1, 0);

//   while (q--)
//   {
//     cin >> a >> b;
//     cout << lca(a - 1, b - 1) + 1 << endl;
//   }
// }
// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

//   solve();
//   return 0;
// }