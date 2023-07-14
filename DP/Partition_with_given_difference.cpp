// Problem Statement

// Given an array 'ARR', partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be 'S1' and 'S2'. Given a difference 'D', count the number of partitions in which 'S1' is greater than or equal to 'S2' and the difference between 'S1' and 'S2' is equal to 'D'. Since the answer may be too large, return it modulo *10^9 + 7'.

// If 'Pi_Sj' denotes the Subset 'j' for Partition 'i'. Then, two partitions P1 and P2 are considered different if:
// 1) P1_51 != P2_51 i.e, at least one of the elements of P1_51 is different from P2_S2.
// 2) P1_51 P2_52, but the indices set represented by P1_51 is not equal == to the indices set of P2_52. Here, the indices set of P1_51 is formed by taking the indices of the elements from which the subset is formed. Refer to the example below for clarification.

#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007
int func(int ind, int d,int s, int sum, vector<int>&arr,vector<vector<int>>&dp)
{
    if (ind < 0) return ((sum - s) - s == d); //We go till index 0 because ((sum - s) - s == d) this is value at index is checked at index -1 and for 2 it is checked at 1 and so on.. and it might contain value 0 so we have to go till last ind 

    if(dp[ind][s] != -1) return dp[ind][s];
    return dp[ind][s] = (func(ind-1,d,s,sum,arr,dp) + func(ind-1,d,s+arr[ind],sum,arr,dp)) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(auto it : arr) sum += it;
    int s = 0;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return func(n-1,d,s,sum,arr,dp) % mod;
}

// Another way 
// -->  as (sum - 2*s) = d => s = (sum - d)/2;
//So question boils down to find (number of subsets with target == s)
