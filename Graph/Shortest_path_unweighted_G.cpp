// CPP code for printing shortest path between two vertices of unweighted graph
#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int printShortestDistance(vector<int>adj[], int src,int dest,int v)
{
    queue<int>q;
    vector<int>dist(v,1e5);

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            int x = dist[node] + 1;
            if(x < dist[it])
            {
                dist[it] = x;
                q.push(it);
            }
        }
    }

    return dist[dest];
}

int main()
{
	// no. of vertices
	int v = 8;

	// array of vectors is used to store the graph
	// in the form of an adjacency list
	vector<int> adj[v];

	// Creating graph given in the above diagram.
	// add_edge function takes adjacency list, source
	// and destination vertex as argument and forms
	// an edge between them.
	add_edge(adj, 0, 1);
	add_edge(adj, 0, 3);
	add_edge(adj, 1, 2);
	add_edge(adj, 3, 4);
	add_edge(adj, 3, 7);
	add_edge(adj, 4, 5);
	add_edge(adj, 4, 6);
	add_edge(adj, 4, 7);
	add_edge(adj, 5, 6);
	add_edge(adj, 6, 7);
	int source = 2, dest = 6;
	cout<< printShortestDistance(adj, source, dest, v);
	return 0;
}
