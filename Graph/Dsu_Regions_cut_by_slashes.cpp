//  Leetcode -> 959. Regions Cut By Slashes

// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
// Given the grid grid represented as a string array, return the number of regions.
// Note that backslash characters are escaped, so a '\' is represented as '\\'.

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
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
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();

        DisjointSet ds((n+1)*(n+1));

        // Connect all the outer boundaries
        // *****
        
        // for(int i=0;i<n;i++)
        // {
        //     ds.unionBySize(((i*n)+i),((i+1)*n)+(i+1));
        // }

        // for(int i=0;i<n;i++)
        // {
        //     ds.unionBySize((((i+1)*n) + i) ,(((i+2)*n) + i+1));
        // }

        // for(int j=0;j<n;j++)
        // {
        //     ds.unionBySize(j,j+1);
        // }

        // for(int j=0;j<n;j++)
        // {
        //     int x = n*n;
        //     ds.unionBySize(x+(n+j), x+n+(j+1));
        // }

        //OR
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0 || i==n || j==n)
                ds.unionBySize(0,(i*(n+1) + j));
            }
        }
        // ****

        int ans = 1; // Initialized with 1 because 1 complete square will be always there
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == ' ') continue;

                if(grid[i][j] == '/'){

                    int x1 = (i+1);
                    int y1 = j;
                    int x2 = i;
                    int y2 = (j+1);

                    int u = (x1*n)+(y1+x1);
                    int v = (x2*n)+(y2+x2);

                    if(ds.findUPar(u) == ds.findUPar(v)) ans++;

                    else{
                        ds.unionBySize(u,v);
                    }
                }

                else if(grid[i][j] == '\\'){
                    int x1 = i;
                    int y1 = j;
                    int x2 = (i+1);
                    int y2 = (j+1);

                    int u = (x1*n)+(y1+x1);
                    int v = (x2*n)+(y2+x2);

                    if(ds.findUPar(u) == ds.findUPar(v)) ans++;

                    else{
                        ds.unionBySize(u,v);
                    }
                }
            }
        }

        return ans;
    }
};





























