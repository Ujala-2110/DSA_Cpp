#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

// Recursion
/*
int func(int i, int n, string &s)
{
    if (i == n) return 0;

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        // if i -- j is a palindrome
        if (is_palindrome(i, j, s))
        {
            //i...j
            //B A B ABCBADCEDE
            int cost = 1 + func(j + 1, n, s);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}
*/

// Memoization
/*
int func(int i, int n, string &s, vector<int>&dp)
{
    if (i == n) return 0;

    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        // if i -- j is a palindrome
        if (is_palindrome(i, j, s))
        {
            //i...j
            //B A B ABCBADCEDE
            int cost = 1 + func(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[i] = minCost;
}
*/

int func(int n, string &s, vector<int> &dp)
{
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            // if i -- j is a palindrome
            if (is_palindrome(i, j, s))
            {
                // i...j
                // B A B ABCBADCEDE
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[0] - 1;
}

int main()
{
    string str = "BABABCBADCEDE";
    int n = str.length();
    // cout << func(0, n, str) - 1; // minus 1 because it partitions in the last also lik(ancde|)
    // vector<int> dp(n, -1);
    // cout << func(0, n, str, dp) - 1; // minus 1 because it partitions in the last also lik(ancde|)

    vector<int> dp(n+1, 0);
    cout << func(n, str, dp); // minus 1 because it partitions in the last also lik(ancde|)
}