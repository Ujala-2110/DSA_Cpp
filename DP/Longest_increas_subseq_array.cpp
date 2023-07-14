#include <bits/stdc++.h>
using namespace std;

/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    vector<int> b;
    set<int> s;

    // setting iterator for set
    set<int>::iterator it;

    // storing unique elements
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // creating sorted vector
    for (it = s.begin(); it != s.end(); it++)
    {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    // storing -1 in dp multidimensional array
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    // Finding Longest common Subsequence of the two
    // arrays
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

/*
int lis(int arr[], int i, int n, vector<int> &dp)
{
    if (n == 1)  return 1;

    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if(arr[i] > arr[j])
        ans = max(ans,lis(arr,j,n,dp)+1);
    }

    return dp[i] = ans;
}

int longestSubsequence(int a[],int n)
{
    // your code here
    vector<int> dp(n + 1, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    ans = max(ans, lis(a, i, n, dp));

    return ans;
}
*/

// Tabulation
/*
int lis(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
    dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = *max_element(dp, dp + n);
    return result;
}
*/

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of lis is " << lis(arr, n);
    // cout << "Length of lis is " << longestSubsequence(arr, n);
    return 0;
}