// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int minCost(int i, int j, vector<int> &cuts)
{
    if (i > j) return 0;

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + minCost(i, ind - 1,cuts) + minCost(ind + 1, j,cuts);
        mini = min(mini, cost);
    }

    return mini;
}
*/

// Memoization
/*
int minCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + minCost(i, ind - 1, cuts, dp) + minCost(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}
*/

int main()
{
    int n = 7;                    // Length of stick
    vector<int> cuts{1, 3, 4, 5}; // We can cut the stick at these elements
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    // cout << minCost(1, c, cuts);

    // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    // cout << minCost(1, c, cuts, dp);

    // Tabulation
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j) continue;
            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    cout << dp[1][c];
    return 0;
}