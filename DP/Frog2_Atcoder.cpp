#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int h[N], k;

// Recursion
/*
int Mincost(int n)
{
    if (n == 0) return 0;

    int cost = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        cost = min(cost, Mincost(n - i) + abs(h[n] - h[n - i]));
    }

    return cost;
}
*/

// Memoization
/*
int Mincost(vector<int> &dp, int n)
{
    if (n == 0) return 0;

    int cost = INT_MAX;

    if(dp[n] != -1) return dp[n]; // step 2

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        cost = min(cost, Mincost(dp,n - i) + abs(h[n] - h[n - i]));
    }

    return dp[n] = cost; // step 3
}
Time complexity -> O(n*k)
*/

//Tabulation

int Mincost(vector<int> &dp, int n)
{
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i <= n; i++)
    {
        int cost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            cost = min(cost, dp[i-j] + abs(h[i] - h[i - j]));
        }
        dp[i] = cost;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n >> k;

    vector<int> dp(n + 1, -1); //step 1
    for (int i = 0; i < n; i++)
    cin >> h[i];

    // cout << Mincost(n - 1); // For recursion
    cout << Mincost(dp, n - 1);
    return 0;
}