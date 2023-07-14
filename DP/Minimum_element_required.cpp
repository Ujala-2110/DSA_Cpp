// Problem Statement

// You are given an array of 'N' distinct integers and an integer 'X' representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum 'X'.
// Note:
// You have an infinite number of elements of each type.

// For Example
// If N=3 and X=7 and array elements are [1,2,3].
// Way 1 You can take 4 elements [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7. -
// Way 2 - You can take 3 elements [3, 3, 1] as 3 + 3 + 1 = 7.
// Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7. Hence the output is 3.

#include <bits/stdc++.h> 
using namespace std;

int func(int ind,vector<int>&coins,int x,vector<vector<int>>&dp)
{
    if(ind == 0){
        if(x % coins[0] == 0) return x/coins[0];
        return 1e9;
    }

    if(dp[ind][x] != -1) return dp[ind][x];
    
    int take = INT_MAX;
    if(coins[ind] <= x) take = 1+func(ind,coins,x-coins[ind],dp);
    int nottake = func(ind-1,coins,x,dp);
    
    return dp[ind][x] = min(take,nottake);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans = func(n-1,num,x,dp);
    if(ans >= 1e9) return -1;
    return ans;
}

//Tabulation
int minimumElements(vector<int> &coins, int x)
{
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    
    for(int c=0;c<=x;c++){
        if(c % coins[0] == 0) dp[0][c] = c/coins[0];
        else dp[0][c] = 1e9;
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int c=0;c<=x;c++)
        {
            int take = INT_MAX;
            if(coins[ind] <= c) take = 1+dp[ind][c-coins[ind]];
            int nottake = dp[ind-1][c];

            dp[ind][c] = min(take,nottake);
        }
    }
    
    int ans = dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
}

//Space Optimization
int minimumElements(vector<int> &coins, int x)
{
    int n = coins.size();
    vector<int>prev(x+1,0), curr(x+1,0);    
    
    for(int c=0;c<=x;c++){
        if(c % coins[0] == 0) prev[c] = c/coins[0];
        else prev[c] = 1e9;
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int c=0;c<=x;c++)
        {
            int take = INT_MAX;
            if(coins[ind] <= c) take = 1+curr[c-coins[ind]];
            int nottake = prev[c];

            curr[c] = min(take,nottake);
        }
        prev = curr;
    }
    
    int ans = prev[x];
    if(ans >= 1e9) return -1;
    return ans;
}










































