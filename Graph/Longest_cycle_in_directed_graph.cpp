// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
// Return the length of the longest cycle in the graph. If no cycle exists, return -1.
// A cycle is a path that starts and ends at the same node.

// Example 1:
// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.

#include<bits/stdc++.h>
using namespace std;

// Using cycle detection  --> (Ye mst tha) 

  int ans=-1;
    
  void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&pathvis , vector<int>&par , int p = -1)
  {
      vis[node] = 1;
      pathvis[node] = 1;
      par[node] = p;
      
      for(auto it : adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,vis,pathvis,par,node);
          }
          
          else if(pathvis[it])   // Largest sum cycle --> Optimize this
          {
              int cnt = 1;
              int curr_node = node;
              while(curr_node != it)
              {
                cnt ++;
                curr_node = par[curr_node];
              }
              
              ans = max(ans , cnt);
          }
      }
      
      pathvis[node] = 0;
  }
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1)
            {
                adj[i].push_back(edges[i]);
            }
        }
        
       vector<int>vis(n,0);
       vector<int>pathvis(n,0);
       vector<int>par(n,0);
    
       for(int i=0;i<n;i++)
       {
           if(!vis[i]) dfs(i,adj,vis,pathvis,par);
       }
    
        
       return ans;
    }

// Using Dfs

int ans = -1;
void dfs(int node,vector<int>&edges,vector<bool>&vis , unordered_map<int,int>&dist)
{
    vis[node] = 1;
    int ngh = edges[node];

    if(ngh != -1 && !vis[ngh])
    {
        dist[ngh] = dist[node] + 1; //*************************
        dfs(ngh,edges,vis,dist);
    }

    else if(ngh != -1 && dist[ngh] > 0){
        ans = max(ans , dist[node] - dist[ngh] + 1); //****************************
    }
}

int longestCycle(vector<int>& edges) {
    
    int n = edges.size();
    vector<bool>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {  
            unordered_map<int,int>dist;
            dist[i] = 1;

            dfs(i,edges,vis,dist);
        }
    }
    return ans;
}

//Apna flavour

int ans = -1;

void dfs(int node,vector<int>adj[],vector<bool>&vis , unordered_map<int,int>&dist)
{
    vis[node] = 1;
    // int ngh = edges[node];

    for(auto ngh : adj[node])
    {
        if(!vis[ngh])
        {
            dist[ngh] = dist[node] + 1;
            dfs(ngh,adj,vis,dist);
        }

        else if(dist[ngh] > 0){
            ans = max(ans , dist[node] - dist[ngh] + 1);
        }
    }
}

int longestCycle(vector<int>& edges) {
    
    int n = edges.size();
    vector<bool>vis(n,0);

    vector<int>adj[n];

    for(int i=0;i<n;i++)
    {
        if(edges[i] != -1) adj[i].push_back(edges[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {  
            unordered_map<int,int>dist;
            dist[i] = 1;

            dfs(i,adj,vis,dist);
        }
    }
    return ans;
}

//Using kahn's algo

int longestCycle(vector<int>& edges) {
    
    int n = edges.size();
    vector<bool>vis(n,0);

    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
    {
        if(edges[i] != -1)
        {
            indegree[edges[i]]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        vis[node] = true;

        int ngh = edges[node]; // neighbour
        if(ngh != -1)
        {
            indegree[ngh]--;
            if(indegree[ngh] == 0) q.push(ngh);
        }
    }

    int ans = -1;
    //All the nodes involved in the cycle will be unvisited

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int ngh = edges[i];
            vis[i] = 1;
            int cnt = 1;

            while(ngh != i)
            {
                vis[ngh] = 1;
                ngh = edges[ngh];
                cnt++;
            }
            ans = max(ans , cnt);
        }

    }

    return ans;
}