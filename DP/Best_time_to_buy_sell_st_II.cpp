#include<bits/stdc++.h>
using namespace std;

//buy -> 1 means u can buy the stock and 0-> means u cannot.

//Recursion
/*
int maxProfit(int ind , int buy , vector<int>&prices,int n)
{
    if(ind == n) return 0;

    int profit = 0;
    if(buy)
    {
        profit = max(-prices[ind]+maxProfit(ind+1,0,prices,n), maxProfit(ind+1,1,prices,n)); //If we are buying means 
        //we are decreasing the amount so (-prices[ind])
    }
    else
    {
        profit = max(prices[ind]+maxProfit(ind+1,1,prices,n), maxProfit(ind+1,0,prices,n));//If we are selling means we 
        // are incresing the amount so (+prices[ind])
    }

    return profit;
}
*/

//Memoization
int maxProfit(int ind , int buy , vector<int>&prices,int n,vector<vector<int>>&dp)
{
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit = 0;
    if(buy)
    {
        profit = max(-prices[ind]+maxProfit(ind+1,0,prices,n,dp), maxProfit(ind+1,1,prices,n,dp)); //If we are buying means 
        //we are decreasing the amount so (-prices[ind])
    }
    else
    {
        profit = max(prices[ind]+maxProfit(ind+1,1,prices,n,dp), maxProfit(ind+1,0,prices,n,dp));//If we are selling means we 
        // are incresing the amount so (+prices[ind])
    }

    return dp[ind][buy] = profit;
}

//Tabulation
int maxProfit(vector<int>&prices,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1 ; ind >=0 ; ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
            }

            else
            {
                profit = max(prices[ind]+dp[ind+1][1], dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }

    }

    return dp[0][1];
}

//Space Optimization
int maxProfit(vector<int>&prices,int n)
{
    vector<int>prev(2,0) , curr(2,0);
    prev[0] = prev[1] = 0;
 
    for(int ind = n-1 ; ind >=0 ; ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max(-prices[ind]+prev[0], prev[1]);
            }

            else
            {
                profit = max(prices[ind]+prev[1], prev[0]);
            }

            curr[buy] = profit;
        }
        prev = curr;
    }

    return prev[1];
}

//Space Optimization upto 4 variables
int maxProfit(vector<int>&prices,int n)
{
    int prevNotbuy , prevBuy , currNotbuy , currBuy;
    prevNotbuy = 0 , prevBuy = 0;
    
    for(int ind = n-1 ; ind >=0 ; ind--)
    {
        currBuy = max(-prices[ind]+ prevNotbuy, prevBuy);

        currNotbuy = max(prices[ind]+prevBuy, prevNotbuy);
            
        prevNotbuy = currNotbuy;
        prevBuy = currBuy;
    }

    return prevBuy;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Function Call to find the
    // maximum profit possible by
    // buying and selling  stock
    int n = prices.size();
    // int ans = maxProfit(0,1,prices,n);

    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // int ans = maxProfit(0,1,prices,n,dp);
    //Tabulation
    int ans = maxProfit(prices,n);
    cout << ans << endl;

    return 0;
}