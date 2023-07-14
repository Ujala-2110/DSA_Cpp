#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
{
    vector<vector<int>> ans(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j || graph[i][j] == 1)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans[i][j] = ans[i][j] || (ans[i][k] && ans[k][j]);
            }
        }
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    vector<vector<int>> res = transitiveClosure(N, graph);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}