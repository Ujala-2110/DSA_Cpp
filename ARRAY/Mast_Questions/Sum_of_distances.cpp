// You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
// Return the array arr.

// Example 1:

// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]
// Explanation: 
// When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
// When i = 1, arr[1] = 0 because there is no other index with value 3.
// When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
// When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
// When i = 4, arr[4] = 0 because there is no other index with value 2. 


#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<long long> distance(vector<int>& nums) {
    
    int n = nums.size();
    
    map<ll,ll> left_sum , left_cnt , right_sum , right_cnt;

    for(int i=0;i<n;i++)
    {
        right_sum[nums[i]]+=i;
        right_cnt[nums[i]]++;
    }

    vector<ll>ans;

    for(int i=0;i<n;i++)
    {
        left_sum[nums[i]] += i;
        left_cnt[nums[i]]++;

        right_sum[nums[i]] -= i;
        right_cnt[nums[i]]--;

        ll res =  left_cnt[nums[i]]*i - left_sum[nums[i]] + right_sum[nums[i]] - right_cnt[nums[i]]*i;

        ans.push_back(res);
    }

    return ans;
}   