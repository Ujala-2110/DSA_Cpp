#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        
vector<vector<int>>adj[V+1];

for(auto it : edges){
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(V+1, 1e9);
pq.push({0, 1});
dist[1] = 0;

int parent[V+1];

for(int i = 0;i<=V;i++){
    parent[i] = i;
}

while (!pq.empty())
{
    int curr = pq.top().second;
    int curr_d = pq.top().first;
    pq.pop();

    for (auto edge : adj[curr])
    {
        if (curr_d + edge[1] < dist[edge[0]])
        {
            parent[edge[0]] = curr;
            dist[edge[0]] = curr_d + edge[1];
            pq.push({dist[edge[0]], edge[0]});
        }
    }
}

if(dist[V] == 1e9) return {-1};

vector<int>ans;

int x = V;
while(parent[x] != x)
{
    ans.push_back(x);
    x = parent[x];
}
ans.push_back(1);
reverse(ans.begin(), ans.end());
return ans;
}