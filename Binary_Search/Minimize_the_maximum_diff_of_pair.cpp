// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
// Return the minimum maximum difference among all p pairs.

// Example 1:
// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>&nums , int p)
{
    int n = nums.size();
    
    for(int i=1;i<n;i++)
    {
        if(nums[i] - nums[i-1] <= mid){
            p--;
            i++;
        }
        
        if(p <= 0) return true;
    }
    
    return false;
}

int minimizeMax(vector<int>& nums, int p) {
    
    if(p == 0) return 0;
    
    int n = nums.size();
    sort(nums.begin(),nums.end());
    
    long ans = 1e11;
    long lo = 0 , hi = 1e11;
    
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        
        if(check(mid,nums,p)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    return ans;
}