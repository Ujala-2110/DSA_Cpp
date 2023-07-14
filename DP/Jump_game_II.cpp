// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include <bits/stdc++.h>
using namespace std;

// minimum number of jumps -> final dest par return 0 and function call me (1 + func(.....)

// Memoization
int func(int ind, vector<int> &nums, int n, vector<int> &dp)
{
    if (ind == n - 1) return 0;

    if (dp[ind] != -1) return dp[ind];

    int ans = 1e9;

    for (int i = ind + 1; i <= min(n - 1, ind + nums[ind]); i++)
    {
        ans = min(ans + 0ll, 1ll + func(i, nums, n, dp));
    }

    return dp[ind] = ans;
}

// TC -> O(n^2)
// SC -> O(n)

int jump(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    // return func(0,nums,n,dp);

    /***************************************************/

    // Tabulation
    dp[n - 1] = 0;

    for (int ind = n - 2; ind >= 0; ind--)
    {
        int ans = 1e9;

        for (int i = ind + 1; i <= min(n - 1, ind + nums[ind]); i++)
        {
            ans = min(ans + 0ll, 1ll + dp[i]);
        }

        dp[ind] = ans;
    }

    return dp[0];
}

// Greedy Approach

int jump(vector<int>& nums) {

    int n = nums.size();

    // It's kind of bfs implementation we take [l .. r] as a level
    // Window -> [l .. r]

    int ans = 0 , l = 0 , r = 0;

    while(r < n-1)
    {
        int farthest = 0;
        for(int i=l;i<=r;i++)
        {
            farthest = max(farthest , i + nums[i]);
        }

        l = r+1;
        r = farthest;
        ans++;
    }

    return ans;
}

// Same Approach with different style
int jump(vector<int>& nums) {

    int n = nums.size();

    int ans = 0 , currend = 0 , currfarthest = 0;

    for(int i = 0; i < n - 1 ; i++)
    {
        currfarthest = max(currfarthest , i + nums[i]);

        if(i == currend)
        {
            ans++;
            currend = currfarthest;
        }

        if(currend >= n-1) return ans;
    }

    return ans;
}

