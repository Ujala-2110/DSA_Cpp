#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int func(int ind, int prev_ind, vector<int> &nums, int n)
{
    if (ind == n) return 0;

    int len = func(ind + 1, prev_ind, nums, n); //Not take

    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    len = max(len, 1 + func(ind + 1, ind, nums, n)); //Take

    return len;
}
*/

// Memoization
/*
int func(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>&dp)
{
    if(ind == n) return 0;

    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1]; //(prev_ind+1) because array cannot have -1 as index

    int len = func(ind+1,prev_ind,nums,n,dp);

    if(prev_ind == -1 || nums[ind] > nums[prev_ind])
    len = max(len, 1 + func(ind+1,ind,nums,n,dp));

    return dp[ind][prev_ind+1] = len;
}
*/

// Tabulation
/*
int func(int ind,int prev_ind,vector<int>&nums,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int len = dp[ind+1][prev_ind+1];

            if(prev_ind==-1 || nums[ind] > nums[prev_ind])
            len = max(len, 1+dp[ind+1][ind+1]);

            dp[ind][prev_ind+1] = len;
        }

    }

    return dp[0][-1+1];
}
*/

// Space Optimisation
/*
int func(int ind,int prev_ind,vector<int>&nums,int n)
{
    vector<int>next(n+1,0) , cur(n+1,0);

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int len = next[prev_ind+1];

            if(prev_ind==-1 || nums[ind] > nums[prev_ind])
            len = max(len, 1+next[ind+1]);

            cur[prev_ind+1] = len;
        }

        next = cur;

    }

    return cur[-1+1];
}
*/

/*
int func(vector<int>&nums , int n)
{
    vector<int>dp(n,1);

    int maxi = 1;
    for(int i = 0;i<n;i++)
    {
        for(int prev = 0;prev<i;prev++)
        {
            if(nums[prev] < nums[i])
            dp[i] = max(dp[i],1+dp[prev]);
        }

        maxi = max(maxi , dp[i]);
    }

    return maxi;
}
*/

//
int func(vector<int> &nums, int n)
{
    vector<int> temp;

    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }

        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    return len;
}
// T.C -> O(n * log(n))
// S.C -> O(n)

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = nums.size();

    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // cout << "The length of longest increasing subsequence is " << func(0, -1, nums, n,dp);
    // cout << "The length of longest increasing subsequence is " << func(0, -1, nums, n); //Tabulation

    cout << "The length of longest increasing subsequence is " << func(nums, n);
    return 0;
}
