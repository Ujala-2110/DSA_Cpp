// Good Subarrays

// Given an integer array arr[] of size n. Your task is to count the number of good subarrays of the given array arr.
// Here any subarray arr[l...r] is considered to be good if it satisfies the golden condition.
// Golden condition for a subarray arr[l...r] is that the subarray should have exact X elements in the subarray that have occured at least 3 times in the subarray.
// Note: Subarray arr[l..r] contains all elements arr[l], arr[l+1]...arr[r]
// Example 1:

// Input :
// n=7
// arr={1,2,2,3,3,2,3}
// X=1
// Output:
// 4
// Explanation:
// These 4 suabrrays satisfies the golden 
// condition {1,2,2,3,3,2},{2,2,3,3,2},{2,3,3,2,3},
// {3,3,2,3} we can see in each of four subarrays 
// we have only 1(as X is 1) element that has 
// occured at least 3 times. So answer is 4 as 
// four subarrays were possible.

#include<bits/stdc++.h>
using namespace std;

int Atmostx(int n, int x, vector<int>&arr)
    {
        map<int,int>mp;
        int cnt = 0, left = 0, right = 0;
        
        long long res = 0;
        while(right < n)
        {
            mp[arr[right]]++;
            if(mp[arr[right]] == 3) cnt++;
            right++;
            
            while(cnt > x)
            {
                if(mp[arr[left]] == 3) cnt--;
                mp[arr[left]]--;
                left++;
            }
            
            res += right-left;
        }
        
        return res;
    }
  
    long long goodSubarrays(int n,int x, vector<int>arr) {
        // code here
        return Atmostx(n,x,arr) - Atmostx(n,x-1,arr);
    }