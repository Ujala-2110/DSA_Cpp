// C++ program to check if a connected
// graph is bipartite or not suing DFS
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isBipartite(vector<int> adj[], int v,vector<bool>& visited, vector<int>& color)
{

	for (int u : adj[v]) {

		if (visited[u] == false) {

			visited[u] = true;
			color[u] = !color[v];
			if (!isBipartite(adj, u, visited, color))
				return false;
		}
		// if two adjacent are colored with same color then
		// the graph is not bipartite
		else if (color[u] == color[v])
			return false;
	}
	return true;
}

int main()
{
	// no of nodes
    int N;
	cin>>N;

	vector<int> adj[N + 1];
	vector<bool> visited(N + 1);
	vector<int> color(N + 1);

	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);
	// addEdge(adj, 4, 5);
	// addEdge(adj, 5, 6);
	// addEdge(adj, 6, 1);

	// marking the source node as visited
	visited[1] = true;

	// marking the source node with a color
	color[1] = 0;

	// Function to check if the graph
	// is Bipartite or not
	if (isBipartite(adj, 1, visited, color)) {
		cout << "Graph is Bipartite";
	}
	else {
		cout << "Graph is not Bipartite";
	}

	return 0;
}
