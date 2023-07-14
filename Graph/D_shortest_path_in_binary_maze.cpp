// Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.

// If the path is not possible between source cell and destination cell, then return -1.

// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

// Example 1:

// Input:
// grid[][] = {{1, 1, 1, 1},
//             {1, 1, 0, 1},
//             {1, 1, 1, 1},
//             {1, 1, 0, 0},
//             {1, 0, 0, 1}}
// source = {0, 1}
// destination = {2, 2}
// Output:
// 3
// Explanation:
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 1
// The highlighted part in the matrix denotes the
// shortest path from source to destination cell.

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int x, int y, int n, int m, vector<vector<int>> &grid)
{
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) return false;

    return true;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dst)
{
    int n = grid.size();
    int m = grid[0].size();

    if(src.first==dst.first && src.second==dst.second) return 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    pq.push({0, {src.first, src.second}});
    dist[src.first][src.second] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, n, m, grid) && dis + 1 < dist[nx][ny])
            {
                dist[nx][ny] = dis + 1;
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    if (dist[dst.first][dst.second] == 1e9) return -1;
    return dist[dst.first][dst.second];
}