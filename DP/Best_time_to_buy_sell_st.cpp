#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int max_profit = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        max_profit = max(max_profit, cost);

        mini = min(mini, prices[i]); //we are updating the mini (remembering the past) that's why it comes under dp
        //But we can make it by normal constructive algorithms.
    }

    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Function Call to find the
    // maximum profit possible by
    // buying and selling a single stock
    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}