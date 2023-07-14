// Dijsktra is applicable for (both) directed and undirected graph and Weighted graph.
// It is used to find sortest path between two diffrerent nodes
// It uses greedy method to find shortest distance
// Drawback
// --> It may or may not give correct result in case of negative distance (not valid for negative distance).
// It can be easily implemented by set or Min-heap priority_queue.

#include <bits/stdc++.h>
using namespace std;
#define INF 10000001

vector<pair<int, int>> adj[1001];

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // For directed graph comment one of this
    }
    // priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (pair<int, int> edge : adj[curr])
        {
            if (curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";

    return 0;
}

//Using Set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>>st;
    vector<int> dist(V, 1e9);
    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int curr = it.second;
        int curr_d = it.first;
        st.erase(it);

        for (auto edge : adj[curr])
        {
            if (curr_d + edge[1] < dist[edge[0]])
            {
                if(dist[edge[0]] != 1e9) st.erase({dist[edge[0]],edge[0]});
                dist[edge[0]] = curr_d + edge[1];
                st.insert({dist[edge[0]], edge[0]});
            }
        }
    }
    return dist;
}

//TC -> O(E log V)
//SC -> O(V + E)