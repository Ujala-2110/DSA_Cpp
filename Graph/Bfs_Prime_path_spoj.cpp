#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001];
int dist[10001];
vector<int> primes;

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  dist[src] = 0;

  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    for (int child : adj[curr])
    {
      if (vis[child] == 0)
      {
        vis[child] = 1;
        q.push(child);
        dist[child] = dist[curr] + 1;
      }
    }
  }
}

bool isPrime(int n)
{
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;

  return true;
}

bool isValid(int a, int b)
{
  int cnt = 0;
  while (a > 0)
  {
    if (a % 10 != b % 10)
      cnt++;

    a /= 10;
    b /= 10;
  }

  if (cnt == 1)
    return true;
  else
    return false;
}

void BuildGraph()
{
  for (int i = 1000; i <= 9999; i++)
    if (isPrime(i))
      primes.push_back(i);

  for (int i = 0; i < primes.size(); i++)
  {
    for (int j = i + 1; j < primes.size(); j++)
    {
      int a = primes[i];
      int b = primes[j];

      if (isValid(a, b))
      {
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;

  BuildGraph();
  while (t--)
  {
    int a, b;
    cin >> a >> b;

    for (int i = 1000; i <= 9999; i++)
      dist[i] = -1, vis[i] = 0;

    bfs(a);

    if (dist[b] == -1)
      cout << "Impossible\n";
    else
      cout << dist[b] << "\n";
  }
}

//1033 8179 ---> 6