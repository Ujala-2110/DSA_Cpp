#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Time Complexity N(log(N)) for binary lifting then Q*(log(N)) for all query
// This is different since we are using the in time out time to compute LCA
// N(log(N)) + Q*(log(N))

const int MAXN = 2 * 1e5 + 5;
int intime[MAXN];
int outtime[MAXN];
int globaltime = 0;

void dfs(int current, vector<vector<int>> &edges, int parent, vector<int> &firstparent, vector<int> &levels)
{
  firstparent[current] = parent;
  intime[current] = globaltime++;
  for (auto neigh : edges[current])
  {
    if (neigh != parent)
    {
      levels[neigh] = levels[current] + 1;
      dfs(neigh, edges, current, firstparent, levels);
    }
  }
  outtime[current] = globaltime++;
}

bool is_Ancestor(int x, int y)
{
  if (x == y) return 1;
  return (intime[x] < intime[y] && outtime[x] > outtime[y]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> edges(n + 1, vector<int>());

  for (int i = 2; i <= n; i++)
  {
    int x;
    cin >> x;

    edges[x].push_back(i);
  }

  vector<int> levels(n + 1, 0);

  vector<vector<int>> parents(log2(n) + 1, vector<int>(n + 1));

  dfs(1, edges, -1, parents[0], levels);

  for (int k = 1; k <= log2(n); k++)
  {
    for (int i = 1; i <= n; i++)
    {
      int intermediate = parents[k - 1][i];

      if (intermediate != -1) parents[k][i] = parents[k - 1][intermediate];
      else parents[k][i] = -1;
    }
  }

  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;

    // Lca using intime outime trick

    if (is_Ancestor(x, y)) cout << x << "\n";
    else if (is_Ancestor(y, x)) cout << y << "\n";

    else
    {
      for (int k = log2(n); k >= 0; k--)
      {
        int parent_x = parents[k][x];

        if (!is_Ancestor(parent_x, y) && parent_x != -1)
        {
          x = parent_x;
        }
      }

      cout << parents[0][x] << "\n";
    }
  }

  return 0;
}


// TC -> O(log(n))

void dfs(int current, vector<vector<int>>&edges, int parent, vector<int>&firstparent, vector<int>&levels)
{
  firstparent[current] = parent;

  for(auto neigh : edges[current])
  {
    if(neigh != parent)  
    {
      levels[neigh] = levels[current] + 1;
      dfs(neigh,edges,current,firstparent,levels);
    }
  }
}

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    int n , q;
    cin >> n >> q;

    vector<vector<int>>edges(n+1,vector<int>());

    for(int i=2;i<=n;i++)
    {
      int x;
      cin>>x;

      edges[x].push_back(i);
    }

    vector<int>levels(n+1,0);

    vector<vector<int>>parents(log2(n)+1 , vector<int>(n+1));
    
    dfs(1,edges,-1,parents[0],levels);

    // for(int i=0;i<n;i++) cout<<levels[i]<<"  ";

    for(int k=1;k<=log2(n);k++)
    {
      for(int i=1;i<=n;i++)
      {
        int intermediate = parents[k-1][i];

        if(intermediate != -1) parents[k][i] = parents[k-1][intermediate];
        else parents[k][i] = -1;
      }
    }

    for(int i=0;i<q;i++)
    {
      int a,b;
      cin>>a>>b;

      // Lca
     
      // Make a,b at same level using binary lifting 
      // a,b move upward , until their parents are different 
     
      if(levels[a] > levels[b]) swap(a,b);
     
      ll diff=abs(levels[b] - levels[a]);
      b = KthParent(b,diff,parents);
      
      for(ll i=log2(n); i>=0; i--)
      {
        if(parents[i][a]!=-1 && parents[i][a]!=parents[i][b])
        {
          a=parents[i][a];
          b=parents[i][b];
        }
      }

      if(a == b) cout<<a<<"\n";
      else cout<< parents[0][a]<<"\n";

    }

  return 0;
}


//Using Binary search 

// TC -> O(log(n)*log(n))

void dfs(int current, vector<vector<int>>&edges, int parent, vector<int>&firstparent, vector<int>&levels, int lvl)
{
  firstparent[current] = parent;
  levels[current] = lvl;

  for(auto neigh : edges[current])
  {
    if(neigh != parent)  
    {
      dfs(neigh,edges,current,firstparent,levels,lvl+1);
    }
  }
}

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

int Find_node(int a, int b, vector<vector<int>>&parents , vector<int>&levels)
{
  
  int l = 0 , r = levels[a];
  int ans = 0;

  while(l <= r)
  {
    int mid = (l + r) >> 1;

    if(KthParent(a,mid,parents) != KthParent(b,mid,parents)) 
    {
      ans = max(ans , mid);
      l = mid+1;
    }

    else r = mid-1;
  }

  return ans;
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
    int n , q;
    cin >> n >> q;

    vector<vector<int>>edges(n+1,vector<int>());

    for(int i=2;i<=n;i++)
    {
      int x;
      cin>>x;

      edges[x].push_back(i);
    }

    vector<int>levels(n+1,1);

    vector<vector<int>>parents(log2(n)+1 , vector<int>(n+1));
    
    dfs(1,edges,-1,parents[0],levels,0);

    // for(int i=0;i<n;i++) cout<<levels[i]<<"  ";

    for(int k=1;k<=log2(n);k++)
    {
      for(int i=1;i<=n;i++)
      {
        int intermediate = parents[k-1][i];

        if(intermediate != -1) parents[k][i] = parents[k-1][intermediate];
        else parents[k][i] = -1;
      }
    }

    for(int i=0;i<q;i++)
    {
      int a,b;
      cin>>a>>b;

      // Lca 

      // First  -> calculate levels of both the nodes and make them equal
      // Second -> Do binary Search to calculate last node that is not same
      // Third  -> answer will be parent[last node that is not equal]


      // First Step 
      int lev_a = levels[a];
      int lev_b = levels[b];

      if(lev_a != lev_b)
      {
        if(lev_a > lev_b)
        {
          int k = lev_a - lev_b;
          a = KthParent(a,k,parents);
        }

        else {
          int k = lev_b - lev_a;
          b = KthParent(b,k,parents);
        }
      }

      // Second Step
      int jump = Find_node(a,b,parents,levels);

      // Third Step

      a = KthParent(a,jump,parents);
      b = KthParent(b,jump,parents);

      if(a == b) cout<<a<<"\n";
      else cout<<parents[0][a]<<"\n";

    }

  // }

  return 0;
}