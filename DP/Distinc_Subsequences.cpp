#include <bits/stdc++.h>
using namespace std;

double dp[1005][1005];
int func(string s, string t, int n, int m)
{
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            }

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return int(dp[n][m]);
}

// Memoization
/*
int func(string s, string t, int n, int m)
{
    if (m < 0)
        return 1; // If smaller string exhausted that means we found a solution
    if (n < 0)
        return 0; // If larger string exhausted that means there is no subsequence available

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n] == t[m])
        return dp[n][m] = (func(s, t, n - 1, m - 1) + func(s, t, n - 1, m));

    else
        return dp[n][m] = func(s, t, n - 1, m);
}
*/

//Space Optimization

int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double>curr(m+1,0) , prev(m+1,0); 

        prev[0] = curr[0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]) curr[j] = (prev[j-1] + prev[j]);
                
                else curr[j] = prev[j];
            }

            prev = curr;
        }

        return int(prev[m]);
}
    
//Space Optimization to 1 array

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    // vector<vector<double>>dp(n+1,vector<double>(m+1,0));
//     return func(t,s,n-1,m-1,dp) % mod;
    vector<double>prev(m+1,0); 

    // for(int i=0;i<=n;i++) prev[0] = 1;
    // for(int j=1;j<=m;j++) prev[j] = 0;

    prev[0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(s[i-1] == t[j-1]) prev[j] = (prev[j-1] + prev[j]);
            
            // else prev[j] = prev[j];
        }

    }

    return int(prev[m]);
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // memset(dp, -1, sizeof(dp));
    // return func(s, t, n - 1, m - 1);
    return func(s, t, n, m);
}

int main()
{
    string s = "rabbbit";
    string t = "rabbit";

    cout << numDistinct(s, t);
    return 0;
}
