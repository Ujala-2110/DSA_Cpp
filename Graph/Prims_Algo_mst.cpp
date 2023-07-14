#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;

    vector<pair<int, int>> adj[N];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int parent[N];
    int key[N];
    bool mstset[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = 1e5;
        mstset[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap

    key[0] = 0; // Starting node
    parent[0] = -1;
    pq.push({0, 0});

    for (int count = 0; count < N - 1; count++) // N-1 edges in MST
    {
        int u = pq.top().second;
        pq.pop();

        mstset[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (mstset[v] == false && weight < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << "\n";
        sum += key[i];
    }

    cout << sum << "\n";

    return 0;
}

//MST
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>vis(V,0);

    //Minimum node nikalo (agar wo visited nahi hai to) add karo  and usse connected sare rakho 

    pq.push({0,0});
    int sum = 0;
    while(!pq.empty())
    {
        int edW = pq.top().first;
        int node = pq.top().second;
        pq.pop();
    
        if(vis[node] == 1) continue;
        
        vis[node] = 1;
        sum += edW;
        
        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int adjWt = it[1];
            
            if(!vis[adjNode])
            pq.push({adjWt,adjNode});
        }
    }
    
    return sum;
}

//MST with all nodes forming  mst
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    
    vector<int>vis(V,0);
    vector<pair<int,int>>ans;
    // node ke sare adjacent me jo minimum hota hai wo liya jata hai (greedy)
    pq.push({0,{0,-1}});
    int sum = 0;
    while(!pq.empty())
    {
        int edW = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
    
        if(vis[node] == 1) continue;
        
        vis[node] = 1;
        
        if(par != -1)
        ans.push_back({par,node});
        
        sum += edW;
        
        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int adjWt = it[1];
            
            if(!vis[adjNode]) pq.push({adjWt,{adjNode,node}});
        }
    }
    
    for(auto it : ans) cout<<it.first<<" "<<it.second<<"\n";
    return sum;
}

// TC -> O((V+E)log(V))
// TC -> O(V+E)