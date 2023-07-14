// You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
// The kth ancestor of a tree node is the kth node in the path from that node to the root node.

// Implement the TreeAncestor class:
// TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
// int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    
    //Binary Lifting
    vector<vector<int>>v;

    TreeAncestor(int n, vector<int>& parent) {

        vector<vector<int>> par(n, vector<int>(20));

        for (int i = 0; i < n; i++) par[i][0] = parent[i]; // 1st parent

        for (int j = 1; j < 20; j++) {

            for (int i = 0; i < n; i++) {

                if (par[i][j - 1] == -1) par[i][j] = -1;

                else par[i][j] = par[par[i][j - 1]][j - 1]; // 2nd parent---> 1st parent of 1st parent || 4th parent ----> 2nd parent of 2nd parent
            }
        }
        swap(v, par); // Ye mst chij hai (v ko par bana diya)

    }
    
    int getKthAncestor(int node, int k) {
        
        for (int i = 20; i >= 0; i--) { 

            if ((k >> i) & 1) {// k --> Jumps (k = 19  ==>  10011 ==> (16 + 2 + 1)) ==> (Go to 16th par then to 2nd of that and then 1 to that node)
                node = v[node][i];
                if (node == -1) return -1; //If kth anceestor doesn't exist
            }
        }
        
        return node;
    }
};