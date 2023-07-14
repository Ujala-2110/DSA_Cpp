#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


void dfs(vector<int> g[], int node, int &cnt, int par = -1)
{
  cnt++;

  for (auto ch : g[node])
  {
    if (par == ch) continue;
    dfs(g, ch, cnt, node);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    vector<int> in(n+1,0);
    for (int i = 0; i < n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      in[v]++;
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
      if(in[i] > 1) ans += (in[i]-1);
    }
    cout << (ans) << "\n";
  }
  return 0;
}
