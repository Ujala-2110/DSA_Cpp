// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

// Example 1:

// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}

// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011

// node -> row * m + col

// node -> 0  1  2  3  4
//         5  6  7  8  9
//         10 11 12 13 14
//         15 16 17 18 19

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &op)
{

    DisjointSet ds(n * m);
    vector<int> ans;
    int cnt = 0;

    // node -> row * m + col
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < op.size(); i++)
    {
        int x = op[i][0];
        int y = op[i][1];

        if (vis[x][y] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[x][y] = 1;
        cnt++;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int node = x * m + y;
            int adjNode = nx * m + ny;

            if (is_valid(nx, ny, n, m) && vis[nx][ny] == 1)
            {
                if (ds.findUPar(node) != ds.findUPar(adjNode))
                {
                    cnt--;
                    ds.unionBySize(node, adjNode);
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}
