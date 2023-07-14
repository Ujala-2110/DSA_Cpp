// Problem Statement

// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number "tar".
// Note:
// Two ways are considered different if sets of indexes of elements chosen by these ways are different.
// Input is given such that the answer will fit in a 32-bit integer.

#include <bits/stdc++.h> 
using namespace std;

int func(int ind, int tar , vector<int>&arr , vector<vector<int>>&dp)
{
   if(ind==0){
       if(tar==0 && arr[0]==0) return 2;
       else if(tar == 0 || arr[0]==tar) return 1;
       else return 0;
    }
    
    if(dp[ind][tar] != -1) return dp[ind][tar];
     
    int nottake = func(ind-1,tar,arr,dp);
    int take = 0;
    if(arr[ind] <= tar) take = func(ind-1,tar-arr[ind],arr,dp);
    
    return dp[ind][tar] = take + nottake;   
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return func(n-1,tar,num,dp);
}

//Tabulation
int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1));
    if(nums[0]<=target) dp[0][nums[0]]=1;
    if(nums[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    
    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            int pick=0;
            if(k>=nums[i]) pick=dp[i-1][k-nums[i]];
            int notPick=dp[i-1][k];
            dp[i][k]=pick+notPick;
        }
    }
    return dp[n-1][target];
}

//Space optimization
int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int>prev(target+1,0) , curr(target+1,0) ;
    if(nums[0]<=target) prev[nums[0]]=1;
    if(nums[0]==0) prev[0]=2;
    else prev[0]=1;
    
    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            int pick=0;
            if(k>=nums[i]) pick=prev[k-nums[i]];
            int notPick=prev[k];
            curr[k]=pick+notPick;
        }
        prev = curr;
    }
    return prev[target];
}