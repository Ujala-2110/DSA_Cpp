/* 
For being a Tree
--> Tree has only 1 connected component
--> Tree does not contain any cycle
    No cycle --->(number of edges == no of node-1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001];

void dfs(int node)
{
    vis[node] = 1;
    for (auto ch : adj[node])
        if (vis[ch] == 0)
            dfs(ch);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ct = 0;
    for (int i = 0; i < n; i++)
    if(vis[i]==0)
    {
      dfs(i);
      ct++;
    }

    if(ct==1 || m==n-1)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}