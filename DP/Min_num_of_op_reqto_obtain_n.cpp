// Given an integer N, the task is to obtain N, starting from 1 using minimum number of operations.
// The operations that can be performed in one step are as follows:

// Multiply the number by 2.
// Multiply the number by 3.
// Add 1 to the number.

#include <bits/stdc++.h>
using namespace std;

//Tabulation
/*
int minOperations(int n)
{
    int dp[n + 1];

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {

        dp[i] = INT_MAX;

        // If the number can be obtained
        // by multiplication by 2
        if (i % 2 == 0)
        {
            int x = dp[i / 2];
            if (x + 1 < dp[i])
            {
                dp[i] = x + 1;
            }
        }
        // If the number can be obtained
        // by multiplication by 3
        if (i % 3 == 0)
        {
            int x = dp[i / 3];
            if (x + 1 < dp[i])
            {
                dp[i] = x + 1;
            }
        }

        // Obtaining the number by adding 1
        int x = dp[i - 1];
        if (x + 1 < dp[i])
        {
            dp[i] = x + 1;
        }
    }

    return dp[n];
}
*/

int minOperations(int n, vector<int> &dp)
{
    if (n == 1) return 0;

    if (dp[n] != -1) return dp[n];
    int cost = INT_MAX;
    if (n % 2 == 0) cost = min(cost, minOperations(n / 2, dp));

    if (n % 3 == 0) cost = min(cost, minOperations(n / 3, dp));

    cost = min(cost, minOperations(n - 1, dp));

    return dp[n] = 1 + cost;
}


int main()
{
    int n = 15;
    vector<int> dp(n + 1, -1);
    cout << minOperations(n,dp);
    return 0;
}