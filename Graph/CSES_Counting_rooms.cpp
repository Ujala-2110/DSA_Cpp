#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[1001][1001];
bool vis[1001][1001];

bool isValid(int x, int y)
{
  if (x < 1 || x > N || y < 1 || y > M)
    return false;

  if (vis[x][y] == true || grid[x][y] == '#')
    return false;

  return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
  vis[x][y] = true;
  for (int i = 0; i < 4; i++)
    if (isValid(x + dx[i], y + dy[i]))
      dfs(x + dx[i], y + dy[i]);
}

int main()
{
  cin >> N >> M;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> grid[i][j];

  int cnt = 0;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
      if (vis[i][j] == 0 && grid[i][j] == '.')
      {
        dfs(i, j);
        cnt++;
      }
  }

  cout << cnt;
}
/*
From dots to dots will be counted a room.
*/