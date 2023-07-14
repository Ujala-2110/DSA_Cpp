#include <bits/stdc++.h>
using namespace std;

int dp[310][1001];

// Recursion
/*
int func(int amt, int coins[], int ind)
{
    if (amt == 0) return 1;
    if (ind < 0)  return 0;

    int ways = 0;
    for (int coin_amt = 0; coin_amt <= amt; coin_amt += coins[ind])
    {
        ways += func(amt - coin_amt, coins, ind - 1);
    }
    return ways;
}
*/

// Memoization
/*
int func(int amt, int coins[], int ind)
{
    if (amt == 0) return 1;
    if (ind < 0) return 0;

    if (dp[ind][amt] != -1) return dp[ind][amt];

    int ways = 0;
    for (int coin_amt = 0; coin_amt <= amt; coin_amt += coins[ind])
    {
        if (amt - coin_amt >= 0)
        ways += func(amt - coin_amt, coins, ind - 1);
    }
    return dp[ind][amt] = ways;
}

int count(int coins[], int m, int amt)
{
    memset(dp, -1, sizeof(dp));
    int ans = func(amt, coins, m - 1); //Recursion
    return ans;
}
*/

// Tabulation
int count(int S[], int m, int n)
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[n + 1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for (int i = 0; i < m; i++)
        for (int j = S[i]; j <= n; j++)
            table[j] += table[j - S[i]];

    return table[n];
}

int main()
{
    int arr[] = {1, 2};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    cout << count(arr, m, n);
    return 0;
}

//Memoization
long long int func(int ind, int amt, int coins[], vector<vector<long long int>> &dp)
{
    if (ind < 0 || amt < 0) return 0;

    if (amt == 0) return 1;

    if (dp[ind][amt] != -1) return dp[ind][amt];

    if (coins[ind] > amt) return dp[ind][amt] = func(ind - 1, amt, coins, dp);

    return dp[ind][amt] = (func(ind - 1, amt, coins, dp) + func(ind, amt - coins[ind], coins, dp));
}

//Tabulation
// long long int count(int coins[], int N, int sum)
// {

//     // code here.
//     // vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,0));
//     // return func(N-1,sum,coins,dp);
//     vector<int> curr(sum + 1, 0), prev(sum + 1, 0);
//     for (int i = 0; i < N; i++)
//         dp[i][0] = 1;

//     for (int ind = 1; ind <= N; ind++)
//     {
//         for (int amt = 1; amt <= sum; amt++)
//         {
//             if (coins[ind - 1] > amt)
//                 dp[ind][amt] = dp[ind - 1][amt];

//             else
//                 dp[ind][amt] = dp[ind - 1][amt] + dp[ind][amt - coins[ind - 1]];
//         }
//     }

//     return dp[N][sum];
// }

// // Space Optimization
// long long int count(int coins[], int N, int sum)
// {

//     // code here.
//     // vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,0));
//     // return func(N-1,sum,coins,dp);
//     vector<long long int> curr(sum + 1, 0), prev(sum + 1, 0);
//     for (int i = 0; i < N; i++)
//         curr[0] = 1;

//     for (int ind = 1; ind <= N; ind++)
//     {
//         for (long long int amt = 1; amt <= sum; amt++)
//         {
//             if (coins[ind - 1] > amt)
//                 curr[amt] = prev[amt];

//             else
//                 curr[amt] = prev[amt] + curr[amt - coins[ind - 1]];
//         }

//         prev = curr;
//     }

//     return curr[sum];
// }