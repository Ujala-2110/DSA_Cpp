// Link -> [https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/]

// 1218. Longest Arithmetic Subsequence of Given Difference

// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int d) {
        
    unordered_map<int,int>length;

    int ans = 1;
    for(auto el : arr)
    {
        ans = max(ans , length[el] = (1 + length[el - d]));
    }

    return ans;
}