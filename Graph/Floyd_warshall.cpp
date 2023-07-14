// (WIKIPEDIA)
// In computer science, the Floyd–Warshall algorithm (also known as Floyd's algorithm, the Roy–Warshall algorithm, the Roy–Floyd algorithm, or the WFI algorithm) is an algorithm for finding shortest paths in a directed weighted graph with positive or negative edge weights (but with no negative cycles(A negative cycle is a cycle whose edges sum to a negative value.)).A single execution of the algorithm will find the lengths (summed weights) of shortest paths between all pairs of vertices. Although it does not return details of the paths themselves, it is possible to reconstruct the paths with simple modifications to the algorithm. Versions of the algorithm can also be used for finding the transitive closure of a relation {\displaystyle R}R, or (in connection with the Schulze voting system) widest paths between all pairs of vertices in a weighted graph.

// Behavior with negative cycles 
// A negative cycle is a cycle whose edges sum to a negative value. There is no shortest path between any pair of vertices {\displaystyle i}i, {\displaystyle j}j which form part of a negative cycle, because path-lengths from {\displaystyle i}i to {\displaystyle j}j can be arbitrarily small (negative). For numerically meaningful output, the Floyd–Warshall algorithm assumes that there are no negative cycles. Nevertheless, if there are negative cycles, the Floyd–Warshall algorithm can be used to detect them. The intuition is as follows:

// The Floyd–Warshall algorithm iteratively revises path lengths between all pairs of vertices {\displaystyle (i,j)}(i,j), including where {\displaystyle i=j}i=j;
// Initially, the length of the path {\displaystyle (i,i)}(i,i) is zero;
// A path {\displaystyle [i,k,\ldots ,i]}{\displaystyle [i,k,\ldots ,i]} can only improve upon this if it has length less than zero, i.e. denotes a negative cycle;
// Thus, after the algorithm, {\displaystyle (i,i)}(i,i) will be negative if there exists a negative-length path from {\displaystyle i}i back to {\displaystyle i}i.
// Hence, to detect negative cycles using the Floyd–Warshall algorithm, one can inspect the diagonal of the path matrix, and the presence of a negative number indicates that the graph contains at least one negative cycle.[9] During the execution of the algorithm, if there is a negative cycle, exponentially large numbers can appear, as large as {\displaystyle \Omega (\cdot 6^{n-1}w_{max})}{\displaystyle \Omega (\cdot 6^{n-1}w_{max})}, where {\displaystyle w_{max}}{\displaystyle w_{max}} is the largest absolute value of a negative edge in the graph. To avoid overflow/underflow problems one should check for negative numbers on the diagonal of the path matrix within the inner for loop of the algorithm.[10] Obviously, in an undirected graph a negative edge creates a negative cycle (i.e., a closed walk) involving its incident vertices.

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        matrix[u][v] = wt;
    }

    // Floyd warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF) // To handle negative weight
                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));//This formula is the heart of the Floyd–Warshall algorithm.
            }
        }
    }


    //To detect negative cycle
    for(int i = 1;i<=n;i++)
    {
        if(matrix[i][i] < 0) cout<<"Negative Cycle is present";
    }

    // O(N^3)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == INF)
            cout << "I" << " ";
            else
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}