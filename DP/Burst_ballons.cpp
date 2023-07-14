// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

#include <bits/stdc++.h>
using namespace std;

// Memoization
/*
int maxCoins(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;

    for (int ind = i; ind <= j; ind++)
    {
        int coins = nums[i - 1] * nums[ind] * nums[j + 1] + maxCoins(i, ind - 1, nums, dp) + maxCoins(ind + 1, j, nums, dp);

        maxi = max(coins, maxi);
    }

    return dp[i][j] = maxi;
}
*/

// Tabulation
int maxCoins(int n, vector<int> &nums, vector<vector<int>> &dp)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int coins = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];

                maxi = max(maxi, coins);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

int main()
{
    vector<int> nums{3, 1, 5, 8};
    int n = nums.size();

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    // vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    // cout << maxCoins(1, n, nums, dp);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    cout << maxCoins(n, nums, dp);

    return 0;
}

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167