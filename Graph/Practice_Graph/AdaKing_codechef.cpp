#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

bool is_valid(int x, int y)
{
  if (x < 0 || x == 8 || y < 0 || y == 8) return false;
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
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> grid(8, vector<int>(8, 0));
    vector<vector<int>> vis(8, vector<int>(8, 0));
    int cnt = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {r - 1, c - 1}});
    vis[r - 1][c - 1] = 1;

    while (!q.empty())
    {
      int counter = q.front().first;
      int x = q.front().second.first;
      int y = q.front().second.second;
      q.pop();

      for (int i = 0; i < 8; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_valid(nx, ny) && vis[nx][ny] == 0 && counter < k)
        {
          cnt++;
          q.push({counter + 1,{nx, ny}});
          vis[nx][ny] = 1;
        }
      }
    }

    // for(int i=0;i<8;i++)
    // {
    //   for(int j=0;j<8;j++)
    //   {
    //     if(vis[i][j] == 1) cnt++;
    //   }
    // }

    cout<<cnt+1<<"\n";
  }
  return 0;
}
