#include <bits/stdc++.h>
using namespace std;
#define ll long long


int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

bool is_valid(int x, int y, vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  if (x < 0 || x == n || y < 0 || y == m)
    return false;
  return true;
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
        maxi = max(maxi, grid[i][j]);
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == maxi)
          q.push({0, {i, j}});
      }
    }
    
    int ans = 0;
    while (!q.empty())
    {
      int c = q.front().first;
      int x = q.front().second.first;
      int y = q.front().second.second;
      q.pop();


      for (int k = 0; k < 8; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (is_valid(nx, ny, grid) && vis[nx][ny] == 0 && grid[nx][ny] != maxi)
        {
          vis[nx][ny] = 1;
          q.push({c + 1, {nx, ny}});
          ans = max(ans,c+1);
        }
      }
    }
    
    cout<<ans<<"\n";
  }
  return 0;
}
