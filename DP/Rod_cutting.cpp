#include <bits/stdc++.h>
using namespace std;

//Memoization
int func(int ind,int max_len, vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind == 0) return max_len*arr[0];
    if(dp[ind][max_len] != -1) return dp[ind][max_len];
    int take = INT_MIN;
    int rod_len = ind+1;
    if(rod_len <= max_len) take = arr[ind]+func(ind,max_len-rod_len,arr,dp);
    int nottake = func(ind-1,max_len,arr,dp);
    
    return dp[ind][max_len] = max(take,nottake);
}

int cutRod(vector<int> &arr, int n)
{
    int max_len = n;
    vector<vector<int>>dp(n,vector<int>(max_len+1,-1));
    return func(n-1,max_len,arr,dp);
}

//Tabulation

int cutRod(vector<int> &arr, int n)
{
    int max_len = n;
    vector<int>sizes(n,0);
    for(int i=0;i<n;i++) sizes[i] = i+1;
    vector<vector<int>>dp(n,vector<int>(max_len+1,0));
    
    for(int l = 0;l<=max_len;l++) dp[0][l] = l*arr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int l=0;l<=max_len;l++)
        {
            int take = INT_MIN;
            int rod_len = ind+1;
            if(rod_len <= l) take = arr[ind]+dp[ind][l-rod_len];
            int nottake = dp[ind-1][l];

            dp[ind][l] = max(take,nottake);
        }
    }
    
    return dp[n-1][max_len];
}


//Space Optimization
int cutRod(vector<int> &arr, int n)
{
    int max_len = n;
    
    vector<int>prev(max_len+1,0) , curr(max_len+1,0);
    for(int l = 0;l<=max_len;l++) prev[l] = l*arr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int l=0;l<=max_len;l++)
        {
            int take = INT_MIN;
            int rod_len = ind+1;
            if(rod_len <= l) take = arr[ind]+curr[l-rod_len];
            int nottake = prev[l];

            curr[l] = max(take,nottake);
        }
        
        prev = curr;
    }
    
    return prev[max_len];
}

//Space Optimization to 1 array

int cutRod(vector<int> &arr, int n)
{
    int max_len = n;
    
    vector<int>prev(max_len+1,0);
    for(int l = 0;l<=max_len;l++) prev[l] = l*arr[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int l=0;l<=max_len;l++)
        {
            int take = INT_MIN;
            int rod_len = ind+1;
            if(rod_len <= l) take = arr[ind]+prev[l-rod_len];
            int nottake = prev[l];

            prev[l] = max(take,nottake);
        }
    }
    
    return prev[max_len];
}
