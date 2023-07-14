// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// Input:
// n = 10
// arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4]
// [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0].


// Intution
// Idea is to use the prefix sum. One observation is if there exist a zero-sum subarray the value of prefix sum will repeat.
// let the given array is arr[] = 1  2  -2  3  -3  0 2
// so the presum array [] =       1  3   1   4  1  1 3
// 1 and 3 are repeating it means there zero-sum subarray. The zero-sum subarray exists in between two repeating presum values. So if the presum value repeat 2 times there is 1 zero-sum subarray. If the presum value repeat 3 times there is 3 zero-sum subarray (3C2 rule).

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

long long int findSubarray(vector<long long int> &arr, int n ) {
    //code here
    
    ll ans = 0;
    ll sum = 0;
    unordered_map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        
        if(sum == 0) ans++; // 0......i subarray
        
        if(mp[sum] != 0) ans += mp[sum]; // l......r subarray
        
        mp[sum]++;
    }
    
    return ans;
}
// x_______x that means _______x = 0 (x + 0 == x)

//TC-> O(N)
//SC-> O(N)