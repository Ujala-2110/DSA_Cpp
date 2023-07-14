#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int toDigit(char ch)
{
    return (ch - '0');
}

// Function to find sum of all possible substrings of the given string.
long long sumOfSubstrings(string s)
{
    long long n = s.length();
    long long dp[n + 1];

    dp[0] = toDigit(s[0]);
    for (int i = 1; i < n; i++)
    dp[i] = (10 * dp[i - 1] + (i + 1) * toDigit(s[i])) % mod;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    ans += dp[i];

    return ans % mod;
}

/*
long long sumOfSubstrings(string s)
{
    long long n = s.length();

    long long prev = toDigit(s[0]);
    long long ans = prev;
    for (int i = 1; i < n; i++)
    {
        long long curi = (10 * prev + (i + 1) * toDigit(s[i])) % mod;
        ans += curi;
        prev = curi;
    }
    return ans % mod;
}
*/
// O(1) Space complexity

int main()
{
    string num = "1234";
    cout << sumOfSubstrings(num) << endl;
    return 0;
}
// Example : num = "1234"
// sumofdigit[0] = 1 = 1
// sumofdigit[1] = 2 + 12  = 14
// sumofdigit[2] = 3 + 23  + 123 = 149
// sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
// Result = 1670
// Now we can get the relation between sumofdigit values and can solve the question iteratively. 
// Each sumofdigit can be represented in terms of previous value as shown below, 

// For above example,
// sumofdigit[3] = 4 + 34 + 234 + 1234
//            = 4 + 30 + 4 + 230 + 4 + 1230 + 4
//            = 4*4 + 10*(3 + 23 +123)
//            = 4*4 + 10*(sumofdigit[2])
// In general, 
// sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]