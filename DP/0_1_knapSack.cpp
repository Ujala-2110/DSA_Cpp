#include <bits/stdc++.h>
using namespace std;

//Memoization
int func(int ind, vector<int> wt , vector<int> val , int W ,vector<vector<int>>&dp)
{
    if(ind == 0)
    {
        if(wt[0] <= W) return val[0];
        return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    
    int nottake = 0 + func(ind-1,wt,val,W,dp);
    int take = INT_MIN;
    if(wt[ind] <= W) take = val[ind] + func(ind-1,wt,val,W-wt[ind],dp);
    
    return dp[ind][W] = max(take,nottake);
}

// int knapsack(vector<int> wt, vector<int> val, int n, int W) 
// {
// 	// Write your code here
//     vector<vector<int>> dp(n, vector<int>(W+1, -1));
    
//     return func(n-1,wt,val,W,dp);
   
// }

//Tabulation
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int w = wt[0]; w<=W ;w++) dp[0][w] = val[0];
    
    for(int index = 1; index <n; index++){
        for(int w = 0; w <= W; w++){
            int incl = INT_MIN;
            if(wt[index] <= w)
                incl = val[index] + dp[index -1][w - wt[index]];
            int excl = dp[index - 1][w];

            dp[index][w] = max(incl, excl);
        }
    }
    return dp[n-1][W];
}


//Space Optimization
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
//     vector<vector<int>> dp(n, vector<int>(W+1, 0));
    vector<int>prev(W+1,0) , curr(W+1,0);
    
    for(int w = wt[0]; w<=W ;w++) prev[w] = val[0];
    
    for(int index = 1; index <n; index++){
        for(int w = 0; w <= W; w++){
            int incl = INT_MIN;
            if(wt[index] <= w)
                incl = val[index] + prev[w - wt[index]];
            int excl = prev[w];

            curr[w] = max(incl, excl);
        }
        
        prev = curr;
    }
    return prev[W];
}

//Space Optimization upto 1 row (N)
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
    vector<int>prev(W+1,0);
    
    for(int w = wt[0]; w<=W ;w++) prev[w] = val[0];
    
    for(int index = 1; index <n; index++){
        for(int w = W; w >= 0; w--){ // We are starting from right because we do not required value in right side and we can vhange it in same row from right
            int incl = INT_MIN;
            if(wt[index] <= w)
                incl = val[index] + prev[w - wt[index]];
            int excl = prev[w];

            prev[w] = max(incl, excl);
        }
    }
    return prev[W];
}

int main()
{
    vector<int>val = {60, 100, 120};
    vector<int>wt = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    // vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1)); //step->1 initialising dp with -1 (two states - W & n -> so 2d dp)
    cout << knapsack(wt, val, n,W);
    return 0;
}