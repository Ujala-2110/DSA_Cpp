// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

#include<bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int>&arr,int k)
{
    int n = arr.size();
    long long ans = 0 , sum = 0;
    
    unordered_map<int,int>mp;
    bool flag = true;
    for(int i=0;i<k;i++)
    {
        if(mp[arr[i]]) flag = false;
        
        sum += arr[i];
        mp[arr[i]]++;
    }
    
    if(flag) ans = max(ans,sum);
    
    for(int i=k;i<n;i++)
    {
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0) mp.erase(arr[i-k]);
        sum -= arr[i-k];
        
        mp[arr[i]]++;
        sum += arr[i];
        
        if(mp.size() == k) ans = max(ans,sum);
    }
    
    return ans;
}

int main()
{
    vector<int>nums = {1,5,4,2,9,9,9};
    int k = 3;
    cout<<maximumSubarraySum(nums,k);
    return 0;
}