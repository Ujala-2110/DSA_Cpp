// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

// Example 1:
// Input:
// nums = {2, 8, 5, 4}
// Output:
// 1
// Explaination:
// swap 8 with 4.

#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums)
{
    int n = nums.size();
    
    map<int,int>mp;
    int cnt = 0;
    
    for(int i=0;i<n;i++) mp[nums[i]] = i;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++)
    {
        if(i == mp[nums[i]]) continue;
        
        else{
            cnt++;
            swap(nums[i],nums[mp[nums[i]]]);
            i--;
        }
    }
    
    return cnt;
}