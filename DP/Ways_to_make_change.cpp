// Problem Statement

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ..... Dn- 1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.

#include<bits/stdc++.h>
using namespace std;

//Memoization
long func(int ind, int coins[],int x,vector<vector<long>>&dp)
{
    if(ind == 0){
        if(x % coins[0] == 0) return 1;
        return 0;
    }
    if(dp[ind][x] != -1) return dp[ind][x];
    
    long take = 0;
    if(coins[ind] <= x) take = func(ind,coins,x-coins[ind],dp);
    long nottake = func(ind-1,coins,x,dp);
    
    return dp[ind][x] = take + nottake;
}

//Tabulation
long countWaysToMakeChange(int *coins, int n, int x)
{
    vector<vector<long>>dp(n,vector<long>(x+1,0));

    for(int c=0;c<=x;c++){
        if(c % coins[0] == 0) dp[0][c] = 1;
        else dp[0][c] = 0;
    }

    for(int ind=1;ind<n;ind++)
    {
        for(int c=0;c<=x;c++)
        {
            long take = 0;
            if(coins[ind] <= c) take = dp[ind][c-coins[ind]];
            long nottake = dp[ind-1][c];

            dp[ind][c] = take + nottake;
        }
    }

    return dp[n-1][x];
}


//Space Optimization
long countWaysToMakeChange(int *coins, int n, int x)
{
    vector<long>prev(x+1,0), curr(x+1,0);    
    
    for(int c=0;c<=x;c++){
        if(c % coins[0] == 0) prev[c] = 1;
        else prev[c] = 0;
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int c=0;c<=x;c++)
        {
            long take = 0;
            if(coins[ind] <= c) take = curr[c-coins[ind]];
            long nottake = prev[c];

            curr[c] = take + nottake;
        }
        prev = curr;
    }
    return prev[x];
}

