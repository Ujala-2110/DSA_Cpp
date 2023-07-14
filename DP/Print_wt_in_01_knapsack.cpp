#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) dp[i][w] = 0;

            else if (wt[i - 1] <= w) dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            
            else dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

void printknapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int res = knapsack(W, wt, val, n, dp);
    cout<<res<<"\n";

        //either the result comes from the top
        // (dp[i-1][w]) or from (val[i-1] + dp[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.

    int w = W;
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == dp[i - 1][w]) continue;
        else
        {
            cout << wt[i - 1] << " ";

            w = w - wt[i - 1];
            res = res - val[i - 1];
        }
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printknapSack(W, wt, val, n);

    return 0;
}