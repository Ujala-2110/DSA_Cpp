#include <bits/stdc++.h>
using namespace std;

//Greedy approach when denominations are uniform
vector<int> func(int amt, vector<int> &coins, int n)
{
    vector<int> ans;

    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--)
    {

        // Find denominations
        while (amt >= coins[i])
        {
            amt -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    return ans;
}

int main()
{
    int N = 16;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = 10;
    vector<int> numbers = func(N, coins, n);
    for (auto u : numbers)
        cout << u << " ";
    return 0;
}