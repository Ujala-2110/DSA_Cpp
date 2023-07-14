// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform 
// the multiplications.

#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int MatrixChainOrder(int arr[], int i, int j)
{
    // Base case
    if (i == j) return 0; // Only one matrix no operation required
    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MatrixChainOrder(arr, i, k) + MatrixChainOrder(arr, k + 1, j);

        if (steps < mini)  mini = steps;
    }

    return mini;
}
*/

// Memoization
/*
int MatrixChainOrder(int arr[], int i, int j,vector<vector<int>> &dp)
{
    // Base case
    if (i == j) return 0; // Only one matrix no operation required
    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MatrixChainOrder(arr, i, k,dp) + MatrixChainOrder(arr, k + 1, j,dp);

        if (steps < mini)  mini = steps;
    }

    return dp[i][j] = mini;
}
*/

//TC -> O(N^2)*N -> O(N^3)
//SC -> O(N^2) + O(N)

// Tabulation
int MatrixChainOrder(int arr[], int n, vector<vector<int>> &dp)
{
    for (int i = 1; i < n; i++) dp[i][i] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini) mini = steps;
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1);
    // vector<vector<int>>dp(n, vector<int>(n,-1));

    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, n, dp);
    return 0;
}