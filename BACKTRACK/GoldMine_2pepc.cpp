#include <bits/stdc++.h>
using namespace std;

int result = 0;
int sum;
bool isSafe(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void Gold_Mine(vector<vector<int>> &grid, int n, int m, int i, int j, vector<vector<int>> &visited, vector<int> &bag)
{
    if (!isSafe(i, j, n, m))
    {
        //out of boundary
        return;
    }

    visited[i][j] = 1;
    if (isSafe(i - 1, j, n, m) && grid[i - 1][j] != 0 && visited[i - 1][j] == 0)
    {
        //Up
        bag.push_back(grid[i][j]);
        Gold_Mine(grid, n, m, i - 1, j, visited, bag);
    }
    if (isSafe(i + 1, j, n, m) && grid[i + 1][j] != 0 && visited[i + 1][j] == 0)
    {
        //Down
        bag.push_back(grid[i][j]);
        Gold_Mine(grid, n, m, i + 1, j, visited, bag);
    }
    if (isSafe(i, j + 1, n, m) && grid[i][j + 1] != 0 && visited[i][j + 1] == 0)
    {
        //Right
        bag.push_back(grid[i][j]);
        Gold_Mine(grid, n, m, i, j + 1, visited, bag);
    }
    if (isSafe(i, j - 1, n, m) && grid[i][j - 1] != 0 && visited[i][j - 1] == 0)
    {
        //Left
        bag.push_back(grid[i][j]);
        Gold_Mine(grid, n, m, i, j - 1, visited, bag);
    }

    // visited[i][j] = 0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0 && visited[i][j] == 0)
            {
                vector<int> bag;
                Gold_Mine(grid, n, m, i, j, visited, bag);

                int sum = 0;
                for (int val : bag)
                    sum += val;

                result = max(result, sum);
            }
        }
    }

    cout << result;
    return 0;
}