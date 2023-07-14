// Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) 
// such that all cells along the path are in increasing order with a difference of 1. 
// We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) 
// with the condition that the adjacent cells have a difference of 1.

#include <bits/stdc++.h>
using namespace std;

int n;
int func(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp)
{
    if (i < 0 || i >= n || j < 0 || j >= n) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;

    if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
        x = 1 + func(i, j + 1, mat, dp);

    if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1]))
        y = 1 + func(i, j - 1, mat, dp);

    if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j]))
        z = 1 + func(i - 1, j, mat, dp);

    if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
        w = 1 + func(i + 1, j, mat, dp);

    return dp[i][j] = max({x, y, z, w, 1});
}

int findLongestCell(vector<vector<int>>&mat)
{
    int result = 1;

    vector<vector<int>>dp(n, vector<int>(n,-1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1) func(i, j, mat, dp);
            result = max(result, dp[i][j]);
        }
    }

    return result;
}

int main()
{
    cin>>n;

    vector<vector<int>>mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << findLongestCell(mat);
    return 0;
}
