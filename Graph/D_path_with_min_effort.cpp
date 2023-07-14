// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Example 1:

// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explaination: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int x, int y, int n, int m, vector<vector<int>> &grid)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return false;

    return true;
}

int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == m - 1) return dis;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, n, m, heights))
            {
                int newdis = max(dis, abs(heights[nx][ny] - heights[x][y]));

                if (newdis < dist[nx][ny])
                {
                    dist[nx][ny] = newdis;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }

    // return dist[n-1][m-1];
}