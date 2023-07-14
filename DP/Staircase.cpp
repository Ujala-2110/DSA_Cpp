#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
// const int N = 1e5 + 10;

// int dp[N];

//Memoization
/*
int Nthpoint(vector<int> &dp, int n)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (Nthpoint(dp, n - 1) + Nthpoint(dp, n - 2)) % mod;
}
*/

//Tabulation
int Nthpoint(vector<int> &dp, int n)
{
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    // memset(dp, -1, sizeof(dp));

    vector<int> dp(n + 1, -1);
    int ans = Nthpoint(dp, n);
    cout << "Total no of ways is " << ans % mod;
    return 0;
}