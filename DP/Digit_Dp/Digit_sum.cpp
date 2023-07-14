// Calculate sum of digits in the range l to r

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int arr[1001];
ll dp[11][100][2];

ll getSum(int pos, int n, ll sum , bool flag)
{
  if(pos > n) return sum;

  if(dp[pos][sum][flag] != -1) return dp[pos][sum][flag];

  int lim = 9; // If previous number is less or something then lim will be 9
  if(!flag) lim = arr[pos]; 

  ll res = 0;
  for(int i=0;i<=lim;i++)
  {
    if(flag || i < lim) res += getSum(pos+1, n, sum + i, true);
    else res += getSum(pos+1, n, sum + i, false);
  }

  return dp[pos][sum][flag] = res;
}

ll digitSum(string a)
{
  ll res = 0;
  for(int i=0;i<a.size();i++) res += a[i] - '0';

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--)
  {
    string a,b;
    cin>>a>>b;

    ll L,R;

    for(int i=0;i<a.size();i++) arr[i+1] = a[i] - '0';
    memset(dp, -1, sizeof(dp));

    L = getSum(1,a.size(),0,0);

    for(int i=0;i<b.size();i++) arr[i+1] = b[i] - '0';
    memset(dp, -1, sizeof(dp));

    R = getSum(1,b.size(),0,0);

    ll res = R - L + digitSum(a);

    cout<<res<<"\n";
  }

  return 0;
}