#include<bits/stdc++.h>
using namespace std;

int visited[20005];

void dfs(int curr, vector<vector<int>>& edges, vector<bool>& visited){
    visited[curr] = true;
    for(auto i : edges[curr]){
        if(!visited[i]){
            dfs(i, edges, visited);
        }
    }
}
void bfs(int src, vector<vector<int>>& edges){
    int n = edges.size();
    vector<bool> visisted(n);
    queue<int> q;
    vector<int> dist(n, 1e9);
    visited[src] = true;
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : edges[curr]){
            if(!visited[i]){
                q.push(i);
                dist[i] = dist[curr] + 1;
                visited[i] = true;
            }
        }
    }
}

void multiSourceBFS(int src, vector<vector<int>>& edges, vector<int> specialNodes){
    int n = edges.size();
    vector<bool> visisted(n);
    queue<int> q;
    vector<int> dist(n, 1e9);
    for(auto i : specialNodes){
        dist[i] = 0;
        visited[i] = true;
        q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : edges[curr]){
            if(!visited[i]){
                q.push(i);
                dist[i] = dist[curr] + 1;
                visited[i] = true;
            }
        }
    }
}