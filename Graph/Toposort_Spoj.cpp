// Question->

// Sandro is a well organised person. Every day he makes a list of things which need to be done and enumerates them from 1 to n. However, some things need to be done before others. In this task you have to find out whether Sandro can solve all his duties and if so, print the correct order.

// Input

// In the first line you are given an integer n and m (1<=n<=10000, 1<=m<=1000000). On the next m lines there are two distinct integers x and y, (1<=x,y<=10000) describing that job x needs to be done before job y.

// Output

// Print "Sandro fails." if Sandro cannot complete all his duties on the list. If there is a solution print the correct ordering, the jobs to be done separated by a whitespace. If there are multiple solutions print the one, whose first number is smallest, if there are still multiple solutions, print the one whose second number is smallest, and so on.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int indeg[100001];
vector<int> ans;

bool kahns(int n)
{
    // priority_queue<int>pq    Max heap--> Priority queues are a type of container adapters, specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non increasing order (hence we can see that each element of the queue has a priority {fixed order}).

    priority_queue<int, vector<int>, greater<int>> pq; // Min heap--> so that element can be stored in increasing order.

    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int x = pq.top();
        ans.push_back(x);
        pq.pop();

        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                pq.push(it);
        }
    }

    return ans.size() == n;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    if (!kahns(n))
        cout << "Sandro fails";
    else
    {
        // for (int i = 0; i < ans.size(); i++)
        for (int node : ans)
            cout << node << " ";
    }

    return 0;
}
