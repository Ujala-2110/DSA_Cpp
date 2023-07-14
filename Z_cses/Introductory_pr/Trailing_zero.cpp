// Your task is to calculate the number of trailing zeros in the factorial n!

// For example, 20!=2432902008176640000
//  and it has 4
//  trailing zeros.

// Input

// The only input line has an integer n
// Output
// Print the number of trailing zeros in n!

// Constraints
// 1≤n≤109

// Example
// Input:
// 20

// Output:
// 4

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define asort(arr, n) sort(arr, arr + n)
#define dsort(arr, n) sort(arr, arr + n, greater<>())
#define vasort(v) sort(v.begin(), v.end());
#define vdsort(v) sort(v.begin(), v.end(), greater<>());

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;
  
  ll ans = 0;

  // This is a standard algorithm
  for(int i=5;i<=n;i*=5)
  {
    ans += n/i;
  }

  cout<<ans<<"\n";
  return 0;
}
