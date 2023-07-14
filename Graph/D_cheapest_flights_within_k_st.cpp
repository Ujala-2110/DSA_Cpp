// There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:
// Input:
// n = 4
// flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
// src = 0
// dst = 3
// k = 1
// Output:
// 700
// Explanation:
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];

    for (auto it : flights)
    {
        int u = it[0];
        int v = it[1];
        int pr = it[2];

        adj[u].push_back({v, pr});
    }

    queue<pair<int, pair<int, int>>> pq; //We can use priority_queue but here we do not need it because steps are increasing by 1 step only (it is going level wise)

    vector<int> dist(n, 1e9);

    pq.push({0, {src, 0}}); // Here we storing stops first and not the distance as the first element (becaust normal dijkstra using distance fails at 
    // 5 6
    // 0 1 5
    // 1 2 5
    // 0 3 2
    // 3 1 2
    // 1 4 1
    // 4 2 1
    // 0
    // 2
    // 2)

    dist[src] = 0;

    while (!pq.empty())
    {
        int st = pq.front().first;
        int node = pq.front().second.first;
        int dis = pq.front().second.second;
        pq.pop();

        if (st > k) continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (st <= k && dis + edgeWt < dist[adjNode]) //particular stop tak jitna minimum ho stkta hai price hum karenge
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({st + 1, {adjNode, dist[adjNode]}});
            }
            //queue hai to level by level push hota jayega agar koi jyada stop ke sath minimum price ka milega to wo next level me insert ho jayega
        }
    }

    if (dist[dst] == 1e9)
        return -1;

    return dist[dst];
}

// Agar koi {(stop,price)} (2,6) and dusra (3,5) par pahucha rha hai tab hum pahle (2,6) ko consider karenge b/c stop jyada important hai mere liye and then hum consider karenge (3,5).
//But agar koi (2,6) and dusra (2,5) par pahucha rha hai tab (2,5) consider karenge