// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;
 
//Recursion 
int func(int ind, vector<int>&num, int k,int n)
{
    if(ind == n) return 0;

    int maxi = INT_MIN;
    int ans = INT_MIN;
    int len = 0;
    for(int j=ind;j<min(n,ind+k);j++)
    {
        len++;
        maxi = max(maxi , num[j]);
        ans = max(ans , len*maxi + func(j+1,num,k,n));
    }
    
    return ans;
}

//Memoization
int func(int ind, vector<int>&num, int k,int n,vector<int>&dp)
{
    if(ind == n) return 0;
    if(dp[ind] != -1) return dp[ind];

    int maxi = INT_MIN;
    int ans = INT_MIN;
    int len = 0;
    for(int j=ind;j<min(n,ind+k);j++)
    {
        len++;
        maxi = max(maxi , num[j]);
        ans = max(ans , len*maxi + func(j+1,num,k,n,dp));
    }

    return dp[ind] = ans;
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int>dp(n,-1);
    return func(0,num,k,n,dp);
}

//Tabulation
int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int>dp(n+1,0);
    // return func(0,num,k,n,dp);

    dp[n] = 0;

    for(int ind=n-1;ind>=0;ind--)
    {
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int len = 0;
        for(int j=ind;j<min(n,ind+k);j++)
        {
            len++;
            maxi = max(maxi , num[j]);
            ans = max(ans , len*maxi + dp[j+1]);
        }

        dp[ind] = ans;
    }

    return dp[0];
}