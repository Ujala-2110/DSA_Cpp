// Your task is to count for k=1,2,…,n
//  the number of ways two knights can be placed on a k×k
//  chessboard so that they do not attack each other.

// Input

// The only input line contains an integer n
// .

// Output

// Print n
//  integers: the results.

// Constraints
// 1≤n≤10000

// Example

// Input:
// 8

// Output:
// 0
// 6
// 28
// 96
// 252
// 550
// 1056
// 1848

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
  cin>>n;
 
  for(int i=1;i<=n;i++)
  {
    ll x = i*i;

    ll tot_par = (x*(x-1))/2;

    if(i > 2) tot_par -= 4*(i-1)*(i-2);
    
    cout<<tot_par<<"\n";
  }
  return 0;
}