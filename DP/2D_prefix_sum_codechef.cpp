// link -> https://www.codechef.com/problems/TRPTSTIC

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(int mid,vector<vector<ll>>&dp, vector<vector<int>>&arr,int n, int m, int k)
{
  for(int i=0;i<n;i++) 
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j] == 0)continue;

      int x = i+mid;
      int y = j+mid;
      x = min(x,n-1);
      y = min(y,m-1);
      
      int low_x = i - mid;
      int low_y = j - mid;
      long long cur = dp[x][y];
      
      if(low_x>0){
        cur -= dp[low_x-1][y];
      }
      
      if((low_y)>0){
        cur -= dp[x][low_y-1];
      }
      
      if((low_x)>0 && (low_y)>0)cur += dp[low_x-1][low_y-1];

      if(cur>=k){
        return true;
      }
    }
  }
  return false;
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
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>>arr(n,vector<int>(m));

    ll sum = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        cin>>arr[i][j];
        sum += arr[i][j];
      }
    }

    if(sum < k+1){
      cout<<-1<<"\n";
      continue;
    }


    //2D prefix sum calculation process
    vector<vector<ll>>dp(n,vector<ll>(m));

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(i == 0 && j == 0)
        {
          dp[i][j] = arr[i][j];
        }

        else if(i == 0)
        {
          dp[i][j] = arr[i][j] + dp[i][j-1];
        }

        else if(j == 0)
        {
          dp[i][j] = arr[i][j] + dp[i-1][j];
        }

        else{
          dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
      }
    }

    int ans = INT_MAX;
    int lo = 0 , hi = max(n,m)-1 ;
    while(lo <= hi)
    {
      int mid = (lo + hi) >> 1;

      if(check(mid,dp,arr,n,m,k+1))
      {
        ans = min(ans , mid);
        hi = mid-1;
      }

      else lo = mid+1;
    }

    cout<< ans<<"\n";
  }

  return 0;
}