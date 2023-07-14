#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int dp[N]; //step->1

/*Method -> 1 (Using Recursion)
int fib(int n)
{
    if (n <= 1) return n;

    return fib(n - 1) + fib(n - 2);
}
*/


/*Method -> 2 (Memoization (Top Down))
int dp[N]  memset(dp, -1, sizeof(dp))  step->1 (create dp array and assign it with any value that will not apear while calculating the solution)
 if (dp[n] != -1) return dp[n]; step->2 If dp[n] already calculated then return the dp[n];
 return dp[n] = fib(n - 1) + fib(n - 2);  step->3 (If dp[n] is already not calculated then we return as well as store in dp[n])*/

/*
int fib(int n)
{
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n]; // step->2

    return dp[n] = fib(n - 1) + fib(n - 2); // step->3
}
*/

// Methid -> 3 (Tabulation(Bottom Up)) 

int fib(int n)
{
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
    dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 5;
    cout << fib(n);
    return 0;
}
