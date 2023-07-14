// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

// Example 1:

// Input:
// n=7, m=10
// edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

// Output:
// 4
// Explaination:

// The four ways to get there in 7 minutes are:
// - 0  6
// - 0  4  6
// - 0  1  2  5  6
// - 0  1  3  5  6

#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    const int mod = 1e9 + 7;
    int m = roads[0].size();

    vector<pair<int, int>> adj[n + 1];
    for (auto it : roads)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                ways[adjNode] = ways[node]; //First time it arrived so directly take the ways it take to reach that node 
                pq.push({dis + edW, adjNode});
            }

            else if (dis + edW == dist[adjNode]) ways[adjNode] += ways[node]; //It arrived here earlier also so add the ways 
        }
    }

    return (ways[n - 1]) % mod;
}