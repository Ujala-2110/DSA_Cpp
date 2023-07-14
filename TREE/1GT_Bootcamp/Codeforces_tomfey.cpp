#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// link -> [https://codeforces.com/problemset/problem/763/A]

//Mine approach

bool dfs(int src, int par, vector<int> adj[], vector<int> &cols, int root)
{
  set<int> st;
  st.insert(cols[src]);

  for (auto it : adj[src])
  {
    if (it != par)
    {
      st.insert(cols[it]);
      if (dfs(it, src, adj, cols, root) == false) return false;
    }
  }

  if (st.size() <= 1) return true;
  if (src == root) return true;
  return false;
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

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> cols(n + 1,0);

  for (int i = 1; i <= n; i++) cin >> cols[i];

  int a = -1, b = -1;

  for (int i = 1; i <= n; i++)
  {
    for (auto it : adj[i])
    {
      if (cols[it] != cols[i])
      {
        a = i;
        b = it;
        break;
      }
    }
  }

  if (a == -1)
  {
    cout << "YES" << endl << 1;
  }

  else{
    int ans1 = dfs(a, -1, adj, cols, a);
    int ans2 = dfs(b, -1, adj, cols, b);

    if (ans1 == 1) cout << "YES" << endl << a;
    else if (ans2 == 1) cout << "YES" << endl << b;
    else cout << "NO\n";
  }

  return 0;
}

//Another approach

bool dfs(int node, int par, vector<int> adj[],vector<int> &cols, int col)
{
  if(cols[node] != col) return false;

  for (auto it : adj[node])
  {
    if(it != par)
    if (!dfs(it, node, adj, cols,col)) return false;
  }

  return true;
}

bool check(int node, vector<int>adj[],vector<int>&cols) {
	for (int child : adj[node]) {
		if (dfs(child, node, adj, cols,cols[child]) == false)return 0;
	}
	return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n;
  cin >> n;

  vector<int> adj[n + 1];

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> cols(n + 1);

  for (int i = 1; i <= n; i++) cin >> cols[i];

  int a = -1, b = -1;

  for (int i = 1; i <= n; i++)
  {
    for (auto it : adj[i])
    {
      if (cols[it] != cols[i])
      {
        a = i;
        b = it;
        break;
      }
    }
  }

  if(a==-1){
    cout<<"YES"<<endl<<1;
	}
  else if(check(a,adj,cols)){
		cout<<"YES"<<endl<<a;
	}
  else if(check(b,adj,cols)){
		cout<<"YES"<<endl<<b;
	}
  else{
		cout<<"NO";
	}

  return 0;
}