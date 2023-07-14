// 990. Satisfiability of Equality Equations (Leetcode)

// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) { //Constructor
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& eq) {
        
        DisjointSet ds(26);

        for(auto it : eq)
        {
            if(it[1] == '='){
                ds.unionBySize((it[0]-'a'), (it[3]-'a'));
            }
        }

        for(auto it : eq){
            if(it[1] == '!'){
                if(ds.findUPar(it[0]-'a') == ds.findUPar(it[3]-'a')) return false;
            }
        }

        return true;
    }
};

//T.C -> O(n)


//Method -> 2

//Using dfs

class Solution {

private:
    void dfs(int node, vector<int>adj[], vector<int>&col, vector<int>&vis,int colr_num)
    {
        vis[node] = 1;
        col[node] = colr_num;

        for(auto it : adj[node])
        {
            if(vis[it] == 0) dfs(it,adj,col,vis,colr_num);
        }
    }

public:
    bool equationsPossible(vector<string>& eq) {

        vector<int>adj[26];
        vector<int>vis(26,0);
        vector<int>col(26,0);

        for(auto it : eq)
        {
            if(it[1] == '=')
            {
                adj[it[0]-'a'].push_back(it[3]-'a');
                adj[it[3]-'a'].push_back(it[0]-'a');
            }
        }

        int color_num = 0;
        for(int i=0;i<26;i++)
        {
            if(vis[i] == 0) dfs(i,adj,col,vis,color_num);
            color_num++;
        }

        for(auto it : eq)
        {
            if(it[1] == '!')
            {
                if(col[it[0]-'a'] == col[it[3] -'a']) return false;
            }
        }

        return true;
    }
};