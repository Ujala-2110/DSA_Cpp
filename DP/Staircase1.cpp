// Question -> A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
//  Implement a method to count how many possible ways the child can run up the stairs.
#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
int findStep(vector<int> &dp, int n)
{
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;

    return findStep(dp, n - 1) + findStep(dp, n - 2) + findStep(dp, n - 3);
}
*/

//Memoization
/*
int findStep(vector<int> &dp, int n)
{
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;

    return findStep(dp, n - 1) + findStep(dp, n - 2) + findStep(dp, n - 3);
}
*/

//Tabulation
int findStep(vector<int> &dp, int n)
{
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    return dp[n];
}

int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << findStep(dp, n);
    return 0;
}
