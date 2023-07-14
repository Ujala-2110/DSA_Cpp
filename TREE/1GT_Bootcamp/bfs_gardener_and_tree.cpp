
// link -> [https://codeforces.com/problemset/problem/1593/E]

#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;

    vector<int> adj[n + 1];

    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
      int u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
      indeg[u]++;
      indeg[v]++;
    }

    queue<int> q;

    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
      if (indeg[i] == 1)
      {
        q.push(i);
        vis[i] = 1;
      }
    }

    while (!q.empty() && k--)
    {
      int sz = q.size();

      for (int i = 0; i < sz; i++)
      {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
          if(vis[it]) continue;

          indeg[it]--;

          if (indeg[it] == 1)
          {
            q.push(it);
            vis[it] = 1;
          }
        }
      }
    }

    ll ans = 0;
    for(int i=1;i<=n;i++) 
    {
      if(indeg[i] > 1) ans++;
    }

    ans += q.size();
    cout<<ans<<"\n";
  }

  return 0;
}