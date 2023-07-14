
#include <bits/stdc++.h>
using namespace std;

//Memoization

int func(int ind, int W, vector<int>&pr , vector<int>&wt, vector<vector<int>>&dp)
{
    if(ind == 0) return (W/wt[0])*pr[0];
    
    if(dp[ind][W] != -1) return dp[ind][W];
    int take = INT_MIN;
    if(wt[ind] <= W) take = pr[ind] + func(ind,W-wt[ind],pr,wt,dp);
    int nottake = func(ind-1,W,pr,wt,dp);
    return dp[ind][W] = max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return func(n-1,w,profit,weight,dp);
}


//Tabulation

int unboundedKnapsack(int n, int W, vector<int> &pr, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    
    for(int w=0;w<=W;w++) dp[0][w] = (w/wt[0])*pr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=W;w++)
        {
            int take = INT_MIN;
            if(wt[ind] <= w) take = pr[ind] + dp[ind][w-wt[ind]];
            int nottake = dp[ind-1][w];
            dp[ind][w] = max(take,nottake);
        }
    }
    
    return dp[n-1][W];
}

//Space Optimization
int unboundedKnapsack(int n, int W, vector<int> &pr, vector<int> &wt)
{
    vector<int>prev(W+1,0) , curr(W+1,0);   
    for(int w=0;w<=W;w++) prev[w] = (w/wt[0])*pr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=W;w++)
        {
            int take = INT_MIN;
            if(wt[ind] <= w) take = pr[ind] + curr[w-wt[ind]];
            int nottake = prev[w];
            curr[w] = max(take,nottake);
        }
        
        prev = curr;
    }
    
    return prev[W];
}


//Space Optimization to 1 array
int unboundedKnapsack(int n, int W, vector<int> &pr, vector<int> &wt)
{
    vector<int>prev(W+1,0);   
    for(int w=0;w<=W;w++) prev[w] = (w/wt[0])*pr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=W;w++)
        {
            int take = INT_MIN;
            if(wt[ind] <= w) take = pr[ind] + prev[w-wt[ind]];
            int nottake = prev[w];
            prev[w] = max(take,nottake);
        }
    }
    
    return prev[W];
}