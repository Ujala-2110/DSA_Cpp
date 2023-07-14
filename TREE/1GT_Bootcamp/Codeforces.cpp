// link -> [https://codeforces.com/problemset/problem/580/C]

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Mine approach

int ans;
 
void dfs(int node, int par, vector<int> adj[], vector<int> &days, vector<int>&prev, vector<int> &cats,int m)
{
 
  if (par == -1)
  {
    if(cats[node] == 1)
    {
      days[node] = 1;
      prev[node] = 1;
    }
  }
 
  else
  {
    if(cats[node] == 1)
    {
      if(prev[par] > 0)
      {
        prev[node] = prev[par] + 1;
      }
 
      else prev[node] = 1;
 
      days[node] = max(days[par] , prev[node]);
    }
 
    else{
 
      prev[node] = 0;
      days[node] = max(days[par] , prev[node]);
    }
  } 
 
  int deg = 0;
  for (auto ch : adj[node])
  {
    if (ch == par) continue;
    deg++;
    dfs(ch, node, adj, days, prev, cats,m);
  }
 
  if(deg == 0 && days[node] <= m) ans++;
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  ll n, m;
  cin >> n >> m;
 
  vector<int> cats(n + 1, 0);
 
  for (int i = 1; i <= n; i++) cin >> cats[i];
 
  vector<int> adj[n + 1];
 
  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
 
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  vector<int> days(n + 1, 0);
  vector<int> prev(n + 1, 0);
  ans = 0;
  dfs(1, -1, adj, days, prev, cats,m);
 
  // for(int i=2;i<=n;i++)
  // {
  //   if((adj[i].size() == 1) && days[i] <= m) ans++;
  // }
 
  cout<<ans<<"\n";
 
  return 0;
}


//Different approach

int dfs(int node, int par, vector<int> adj[], vector<int> &val, int m, int cats)
{
  //Base case
  if (cats > m) return 0;
  if (adj[node].size() == 1 && par != -1) return 1;

  int ans = 0;
  for (auto child : adj[node])
  {
    if (child == par) continue;
    if (val[child] == 1) ans += dfs(child, node, adj, val, m, cats + 1);
    else ans += dfs(child, node, adj, val, m, 0);
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m;
  cin >> n >> m;

  vector<int> cats(n + 1, 0);

  for (int i = 1; i <= n; i++) cin >> cats[i];

  vector<int> adj[n + 1];

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cnt = 0;

  if (cats[1] == 1) cnt++;
  cout << dfs(1, -1, adj, cats, m, cnt);

  return 0;
}