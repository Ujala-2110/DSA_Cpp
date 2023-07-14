// link -> [https://codeforces.com/problemset/problem/1363/C]



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
    ll n, x;
    cin >> n >> x;

    vector<int> adj[n + 1];

    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      
      indeg[u]++;
      indeg[v]++;
    }

    if(indeg[x] <= 1) cout<<"Ayush\n";
   
    else if(n % 2 == 0) cout<<"Ayush\n";
    else cout<<"Ashish\n";

  }

  return 0;
}
