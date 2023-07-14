#include <bits/stdc++.h>
using namespace std;

// Memoization
/*
bool Is_Match(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (i >= 0 && j < 0)
    {
        for (int c = 0; c <= i; c++)
        if (s1[c] != '*')  return false;

        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = Is_Match(s1, s2, i - 1, j - 1, dp);

    if (s1[i] == '*')
        return dp[i][j] = Is_Match(s1, s2, i - 1, j, dp) || Is_Match(s1, s2, i, j - 1, dp);

    return dp[i][j] = false;
}
*/

bool Is_Match(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (s1[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (s1[i-1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main()
{
    string s = "aa";
    string p = "*";

    int n = p.length();
    int m = s.length();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << Is_Match(p, s, n - 1, m - 1, dp);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    cout << Is_Match(p, s, n, m, dp);

    return 0;
}

//Memoization
int func(int i,int j, string&pt , string &s,vector<vector<int>>&dp)
{
    if(i == 0 && j == 0) return true;
    if(i == 0 && j > 0) return false;
    if(i > 0 && j == 0){
        for(int c=1;c<=i;c++){
            if(pt[c-1] != '*') return false;
        }
        return true;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(pt[i-1] == s[j-1] || pt[i-1] == '?') return dp[i][j] = func(i-1,j-1,pt,s,dp);
    if(pt[i-1] == '*') return dp[i][j] =  func(i-1,j,pt,s,dp) || func(i,j-1,pt,s,dp);
    
    return dp[i][j] =  false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.length();
   int m = text.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   return func(n,m,pattern,text,dp);
}


//Tabulation
bool wildcardMatching(string pt, string s)
{
   int n = pt.length();
   int m = s.length();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
//    return func(n,m,pattern,text,dp);
    
    dp[0][0] = true;
    for(int j=1;j<=m;j++) dp[0][j] = false;
    for(int i=1;i<=n;i++)
    {
        bool flag = true;
        for(int c=1;c<=i;c++){
            if(pt[c-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
                if(pt[i-1] == s[j-1] || pt[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(pt[i-1] == '*') dp[i][j] =  dp[i-1][j] || dp[i][j-1];

                else dp[i][j] =  false;
        }
    }
    
    return dp[n][m];
}

//Space Optimization
bool wildcardMatching(string pt, string s)
{
   int n = pt.length();
   int m = s.length();
//    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    vector<bool>curr(m+1,0) , prev(m+1,0);
    
    prev[0] = true;
    for(int j=1;j<=m;j++) prev[j] = false;
    
    for(int i=1;i<=n;i++)
    {
        bool flag = true;
        for(int c=1;c<=i;c++){
            if(pt[c-1] != '*'){
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        
        for(int j=1;j<=m;j++)
        {
                if(pt[i-1] == s[j-1] || pt[i-1] == '?') curr[j] = prev[j-1];
                else if(pt[i-1] == '*') curr[j] =  prev[j] || curr[j-1];

                else curr[j] =  false;
        }
        prev = curr;
    }
    
    return prev[m];
}
