#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    // code here
    vector<long> ways(n, 0);
    vector<long> dis(n, LONG_MAX);
    dis[0] = 0;
    ways[0] = 1;

    //{distance, node}
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    pq.push({0, 0});

    // creating the graph
    //{node, distance}
    vector<pair<long, long>> adj[n];

    for (auto r : roads)
    {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }

    while (pq.empty() == false)
    {
        long currnode = pq.top().second;
        long currdis = pq.top().first;
        pq.pop();

        for (auto x : adj[currnode])
        {
            long no = x.first;
            long dist = x.second;
            // if we are reaching a node with a distance lower than the current available distance then we update the distance of the current node and also put the no of ways to reach the currnode into the adjacent node ways, because we can reach the adj node same no of time as no of times we were able to reach currnode.
            if (currdis + dist < dis[no])
            {
                dis[no] = currdis + dist;
                ways[no] = ways[currnode];
                pq.push({dis[no], no});
            }

            // if again we are able to reach a node with the same distance as available then we add the currnode ways into the adj node because now we can reach the adj node with the same smaller distance from some other paths as well.
            else if (currdis + dist == dis[no])
            {
                ways[no] = (ways[no] + ways[currnode]) % (1000000000 + 7);
            }
        }
    }

    return ways[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int i = 0; i < 3; i++)
        {
            int x;
            cin >> x;

            temp.push_back(x);
        }

        roads.push_back(temp);
    }

    cout << countPaths(n, roads);
    return 0;
}