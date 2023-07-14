#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int eggDrop(int n, int f)
{
    if (f == 0 || f == 1) return f;
    if (n == 1) return f;

    int ans = INT_MAX, res;

    for (int i = 1; i <= f; i++)
    {
        res = max(eggDrop(n - 1, i - 1), eggDrop(n, f - i));
        ans = min(ans, res);
    }

    return ans + 1;
}
*/

// Memoization
/*
int eggDrop(int n, int f, vector<vector<int>> &dp)
{
    if (f == 0 || f == 1) return f;
    if (n == 1) return f;

    if (dp[n][f] != -1) return dp[n][f];
    int ans = INT_MAX, res;

    for (int i = 1; i <= f; i++)
    {
        res = max(eggDrop(n - 1, i - 1, dp), eggDrop(n, f - i, dp));
        ans = min(ans, res);
    }

    return dp[n][f] = ans + 1;
}
*/

// Tabulation
/*
int eggDrop(int n, int k, vector<vector<int>> &dp)
{
   for(int f=1;f<=k;f++) dp[1][f] = f;
    for(int i=1;i<=n;i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int e=2;e<=n;e++)
    {
        for(int f = 2;f<=k;f++)
        {
            int ans = INT_MAX,res;
            for(int i=1;i<=f;i++)
            {
                res = max(dp[e-1][i-1],dp[e][f-i]);
                ans = min(ans, res);
            }
            dp[e][f] = ans+1;
        }
    }

    return dp[n][k];

}
Time Complexity: O(n*k^2).
Auxiliary Space: O(n*k).
*/

// Space Optimization
/*
int eggDrop(int n, int k, vector<vector<int>> &dp)
{
    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    for (int f = 1; f <= k; f++) prev[f] = f;
    for (int i = 1; i <= n; i++)
    {
        cur[0] = 0;
        cur[1] = 1;
    }

    for (int e = 2; e <= n; e++)
    {
        for (int f = 2; f <= k; f++)
        {
            int ans = INT_MAX, res;
            for (int i = 1; i <= f; i++)
            {
                res = max(prev[i - 1], cur[f - i]);
                ans = min(ans, res);
            }
            cur[f] = ans + 1;
        }
        prev = cur;
    }

    return prev[k];
}
*/

// BinarySearch approach
int eggDrop(int n, int k, vector<vector<int>> &memo)
{
    if (k == 0 || k == 1) return k;
    if (n == 1) return k;

    if (memo[n][k] != -1) return memo[n][k];

    int mn = INT_MAX, low = 0, high = k, temp = 0;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        int left = eggDrop(n - 1, mid - 1, memo);
        int right = eggDrop(n, k - mid, memo);

        temp = 1 + max(left, right);

        if (left < right) low = mid + 1;
        else high = mid - 1;

        mn = min(mn, temp);
    }
    return memo[n][k] = mn;
}
//Time: O(n*k*logn), Space: O(n*k)

int main()
{
    int n = 2, k = 10;
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    cout << "Minimum number of trials in worst case with " << n << " eggs and " << k << " floors is " << eggDrop(n, k, dp);
}
