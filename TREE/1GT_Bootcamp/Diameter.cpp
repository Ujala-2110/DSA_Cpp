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
        if (ch == par) continue;
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


//Naya wala


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define asort(arr, n) sort(arr, arr + n)
#define dsort(arr, n) sort(arr, arr + n, greater<>())
#define vasort(v) sort(v.begin(), v.end());
#define vdsort(v) sort(v.begin(), v.end(), greater<>());
// bug(parameter)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
 
// ================================== take ip/op like vector,pairs directly!================================== take care bro
// template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
// template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
// template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
 
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  // ll t;
  // cin >> t;
  // while (t--)
  // {
 
  // }
 
  ll n;
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
  dfs(1, -1, adj, depth);
 
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
 
  dfs(mx_node, -1, adj, depth);
  int ans = -1;
 
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, depth[i]);
  }
 
  cout << ans << "\n";
 
  return 0;
}