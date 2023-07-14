// You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.

// Example 1:

// Input: num1 = "1", num2 = "12", min_num = 1, max_num = 8
// Output: 11
// Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.

// link -> (https://leetcode.com/problems/count-of-integers/description/)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
ll dp[23][2][2][401];

ll countStrings(ll i, bool tight1, bool tight2, ll sum, string &num1, string &num2)
{

    if (sum < 0) return 0;
    if (i == num2.size()) return 1;

    if (dp[i][tight1][tight2][sum] != -1) return dp[i][tight1][tight2][sum];

    ll lo = (tight1) ? num1[i] - '0' : 0;
    ll hi = (tight2) ? num2[i] - '0' : 9;

    ll count = 0;
    for (ll idx = lo; idx <= hi; idx++)
    {
        count = (count % MOD + countStrings(i + 1, tight1 & (idx == lo), tight2 & (idx == hi), sum - idx, num1, num2) % MOD) % MOD;
    }

    return dp[i][tight1][tight2][sum] = count;
}

int count(string num1, string num2, int min_sum, int max_sum)
{

    memset(dp, -1, sizeof(dp));
    string num1extended = "";
    ll n1 = num1.length();
    ll n2 = num2.length();

    ll d = n2 - n1;
    while (d--) num1extended += '0';
    num1extended += num1;

    ll a = countStrings(0, 1, 1, max_sum, num1extended, num2);
    memset(dp, -1, sizeof(dp));

    ll b = countStrings(0, 1, 1, min_sum - 1, num1extended, num2);
    ll ans = (a - b) % MOD;

    return (ans < 0) ? ans + MOD : ans;
}