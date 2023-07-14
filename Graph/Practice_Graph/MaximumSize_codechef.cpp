#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int x, int y, vector<vector<char>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();

  if (x < 0 || x == n || y < 0 || y == m || mat[x][y] == '0') return false;
  return true;
}

void dfs(vector<vector<char>> &mat, vector<vector<int>> &vis, int i, int j, int &cnt)
{
  vis[i][j] = 1;
  cnt++;

  for (int k = 0; k < 4; k++)
  {
    int newX = i + dx[k];
    int newY = j + dy[k];

    if (is_valid(newX, newY, mat) && vis[newX][newY] == 0)
    {
      // cout<<cnt<<" ";
      dfs(mat, vis, newX, newY, cnt);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  // for (int tt = 1; tt <= t; tt++)
  while (t--)
  {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      vector<char> curr;
      for (auto i : s)
      {
        curr.push_back(i);
      }
      mat.push_back(curr);
    }

    vector<int> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (vis[i][j] == 0 && mat[i][j] == '1')
        {
          int cnt = 0;
          //   cout<<i<<" "<<j<<"hi ";
          dfs(mat, vis, i, j, cnt);
          //   cout<<cnt<<" ";
          ans.push_back(cnt);
          // cnt = 0;
        }
      }
    }

    sort(ans.begin(), ans.end(),greater<int>());
    // for(auto it : ans) cout<<it<<" ";
    int res = 0;

    for (int i = 0; i < ans.size(); i++)
    {
      if (i & 1)
        res += ans[i];
    }

    cout << res << "\n";
  }
  return 0;
}
