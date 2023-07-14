// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include <bits/stdc++.h>
using namespace std;

// Memoization
bool func(int ind, vector<int> &nums, int n, vector<int> &dp)
{
    if (ind >= n - 1) return true;
    if (nums[ind] == 0) return false;

    if (dp[ind] != -1) return dp[ind];

    for (int i = ind + 1; i <= min(n - 1, ind + nums[ind]); i++)
    if (func(i, nums, n, dp)) return dp[i] = true; // If we have to ruturn true or false only then we can return as soon as we get true value

    return dp[ind] = false;
}

bool canJump(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(n + 1, -1);
    // return func(0,nums,n,dp);

    // Tabulation
    dp[n - 1] = 1;

    for (int idx = n - 2; idx >= 0; idx--)
    {

        if (nums[idx] == 0)
        {
            dp[idx] = false;
            continue;
        }

        //Tabulate to copy hona chahiye memoization ka
        int flag = 0;
        int reach = idx + nums[idx];
        for (int jump = idx + 1; jump <= min(n - 1, reach); jump++)
        {
            if (dp[jump])
            {
                dp[idx] = true;
                flag = 1;
                break;
            }
        }

        if (!flag) dp[idx] = false;
    }
    return dp[0];
}


// Greedy approach

bool canJump(vector<int>& nums) {

    int n = nums.size();
    
    int goal = n-1;

    // Take the gaol post as index n-1 and then check if we can reach index 0 or not , We will check whether we can reach index
    // n-1 from that index or not if we can reach from that index then we will update our goal index to that index 

    for(int i=n-1;i>=0;i--)
    {
      if(i + nums[i] >= goal) goal = i;
    }

    return goal == 0;
}