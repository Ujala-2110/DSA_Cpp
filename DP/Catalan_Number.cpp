//Background :
/*
Catalan numbers are defined using below formula:

  C_{n} = (2n)!/(n+1)!n! = \prod^{n}_{k=2} \frac{n+k}{k}  for_ n >= 0  

Catalan numbers can also be defined using following recursive formula.
 C_{0} = 1 C_{n+1} = \sum ^{n} _{i=0} C_{i}C_{n-i}   for_ n>=0 

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/

#include <bits/stdc++.h>
using namespace std;

// A recursive function to find nth catalan number
/*
unsigned long int catalan(unsigned int n)
{
  // Base case
  if (n <= 1)
    return 1;

  // catalan(n) is sum of
  // catalan(i)*catalan(n-i-1)
  unsigned long int res = 0;
  for (int i = 0; i < n; i++)
    res += catalan(i) * catalan(n - i - 1);

  return res;
}
*/

// A dynamic programming based function to find nth Catalan number
unsigned long int catalan(unsigned int n)
{
  // Table to store results of subproblems
  unsigned long int dp[n + 1];

  // Initialize first two values in table
  dp[0] = dp[1] = 1;

  // Fill entries in catalan[] using recursive formula
  for (int i = 2; i <= n; i++)
  {
    dp[i] = 0;
    for (int j = 0; j < i; j++)
    dp[i] += dp[j] * dp[i - j - 1];
  }

  // Return last entry
  return dp[n];
}

int main()
{
  for (int i = 0; i < 10; i++)
    cout << catalan(i) << " ";

  return 0;
}