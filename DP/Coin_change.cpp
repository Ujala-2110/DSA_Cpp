#include <bits/stdc++.h>
using namespace std;

int dp[10010];
//Recursion
/*
int func(int amt, int coins[], int m)
{
    if (amt == 0) return 0;

    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (amt - coins[i] >= 0)
        ans = min(ans + 0LL, func(amt - coins[i], coins, m) + 1LL);
    }
    return ans;
}
*/

//Memoization
/*
int func(int amt, int coins[], int m)
{
    if (amt == 0) return 0;

    if (dp[amt] != -1) return dp[amt]; //step -> 2
    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (amt - coins[i] >= 0)
            ans = min(ans + 0LL, func(amt - coins[i], coins, m) + 1LL); //(LL has been taken because INT_MAX +1 can 
            //overflow and give bad result (and min() function only work for same data type so ans + 0LL))
    }
    return dp[amt] = ans; //step -> 3
}
*/

//Tabulation
int func(int amt, int coins[], int m)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result  (V = amt)
    int table[amt + 1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= amt; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i = 1; i <= amt; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                table[i] = sub_res + 1;
            }
    }

    if (table[amt] == INT_MAX) return -1;

    return table[amt];
}

int minCoins(int coins[], int m, int amt)
{
    // int ans = func(amt, coins, m); //Recursion
    // vector<int> dp(m + 1, -1); //step -> 1
    memset(dp, -1, sizeof(dp));
    int ans = func(amt, coins, m);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is " << minCoins(coins, m, V);
    return 0;
}

//Striver
/*

//Memoization

class Solution {
public:
    int dp[15][100005];
    int func(int amt, vector<int>&coins, int m)
    {
        if(m == 0){
            if(amt % coins[0] == 0) return amt/coins[0];
            else return 1e9;
        }
        if(dp[m][amt] != -1) return dp[m][amt];
        int nottake = 0ll + func(amt,coins,m-1);
        int take = INT_MAX;
        
        if(amt >= coins[m]) take = 1ll + func(amt-coins[m],coins,m);
        
        return dp[m][amt] = min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins, n-1);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


//Tabulation

class Solution {
public:
    int dp[15][100005];
    int func(int amt, vector<int>&coins, int m)
    {
        for(int i=0;i<=amt;i++){
             if(i % coins[0] == 0) dp[0][i] = i/coins[0];
             else dp[0][i] = 1e9;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int am = 0;am <= amt; am++)
            {
                int nottake = dp[i-1][am];
                int take = INT_MAX;
                
                if(coins[i] <= am) take = 1ll + dp[i][am-coins[i]];
                
                dp[i][am] = min(nottake,take);
            }
        }
        
        return dp[m-1][amt];
      
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, 0, sizeof(dp));
        int ans = func(amount, coins, n);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


//Space Optimization

class Solution {
public:
    // int dp[15][100005];
    int func(int amt, vector<int>&coins, int m)
    {
        vector<int>cur(amt+1,0), prev(amt+1,0);
        for(int i=0;i<=amt;i++){
             if(i % coins[0] == 0) prev[i] = i/coins[0];
             else prev[i] = 1e9;
        }
        
        
        for(int i=1;i<m;i++)
        {
            for(int am = 0;am <= amt; am++)
            {
                int nottake = prev[am];
                int take = INT_MAX;
                
                if(coins[i] <= am) take = 1ll + cur[am-coins[i]];
                
                cur[am] = min(nottake,take);
            }
            prev = cur;
        }
        
        return prev[amt];
      
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // memset(dp, 0, sizeof(dp));
        int ans = func(amount, coins, n);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};
*/