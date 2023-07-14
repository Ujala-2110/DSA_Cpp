// Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit
//  a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and
//  new transaction can start only when the previous transaction has been completed.

#include <bits/stdc++.h>
using namespace std;

// Memoization
/*
int func(int ind, int buy, int cap, int n, int profits[], vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)  return 0;

    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if (buy)
    {
        profit = max(-profits[ind] + func(ind + 1, 0, cap, n, profits, dp), 0 + func(ind + 1, 1, cap, n, profits, dp));
    }
    else
    {
        profit = max(profits[ind] + func(ind + 1, 1, cap - 1, n, profits, dp), 0 + func(ind + 1, 0, cap, n, profits, dp));
    }

    return dp[ind][buy][cap] = profit;
}
*/

/*
int func(int cap, int n, int profits[])
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(cap + 1, 0)));
    for (int i = 0; i < n; i++)
    {
        for (int buy = 0; buy <= 1; buy++)
        dp[i][buy][0] = 0;
    }

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int c = 0; c <= cap; c++)
        dp[n][buy][c] = 0;
    }

    int profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int c = 1; c <= cap; c++)
            {
                if (buy)
                {
                    profit = max(-profits[ind] + dp[ind + 1][0][c], 0 + dp[ind + 1][1][c]);
                }
                else
                {
                    profit = max(profits[ind] + dp[ind + 1][1][c - 1], 0 + dp[ind + 1][0][c]);
                }

                dp[ind][buy][c] = profit;
            }
        }
    }

    return dp[0][1][cap];
}
*/

//Space Optimization
int maxProfit(vector<int>& profits, int n)
{   
     vector<vector<int>>prev(2, vector<int>(3, 0)) , curr(2,vector<int>(3,0));
    for (int i = 0; i < n; i++)
    {
        for (int buy = 0; buy <= 1; buy++)
        curr[buy][2] = 0;
    }

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int c = 0; c <= 2; c++)
        prev[buy][c] = 0;
    }

    int profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int c = 1; c >= 0; c--)
            {
                if (buy)
                {
                    profit = max(-profits[ind] + prev[0][c], 0 + prev[1][c]);
                }
                else
                {
                    profit = max(profits[ind] + prev[1][c + 1], 0 + prev[0][c]);
                }

                curr[buy][c] = profit;
            }
        }
        prev = curr;
    }

    return prev[1][0];
}

// Optimized approach
/*
int func(int ind,int trans, int cap, int n, int profits[], vector<vector<int>>&dp)
{
    if (ind == n || trans == 2*cap)  return 0;

    if (dp[ind][trans] != -1) return dp[ind][trans];

    int profit = 0;
    if (trans % 2 == 0)
    {
        profit = max(-profits[ind] + func(ind + 1, trans+1, cap, n, profits, dp), 0 + func(ind + 1, trans, cap, n, profits, dp));
    }
    else
    {
        profit = max(profits[ind] + func(ind + 1,trans+ 1, cap - 1, n, profits, dp), 0 + func(ind + 1, trans, cap, n, profits, dp));
    }

    return dp[ind][trans] = profit;
}
*/

// Optimised Tabulation
int func(int k, int n, int profits[])
{
    vector<vector<int>> dp(n + 1, vector<int>((2 * k) + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            if (trans % 2 == 0)
            {
                dp[ind][trans] = max(-profits[ind] + dp[ind + 1][trans + 1], 0 + dp[ind + 1][trans]);
            }
            else
            {
                dp[ind][trans] = max(profits[ind] + dp[ind + 1][trans + 1], 0 + dp[ind + 1][trans]);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    int K = 2;
    int A[] = {10, 22, 5, 75, 65, 80};
    int N = sizeof(A) / sizeof(int);

    // vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(2, vector<int>(K + 1, -1)));//Memoization
    //  vector<vector<int>>dp(N+1,vector<int>((2*K)+1,-1));//Optimization
    //  cout << func(0, 0, K, N, A, dp);

    // cout << func(K, N, A);
    cout << func(K, N, A);
    return 0;
}
