// Given two strings str1 and str2 and below operations that can be performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

// 1. Insert
// 2. Remove
// 3. Replace

#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

//Memoization
/*
int Editdistance(string &s1 , string &s2 , int i, int j , vector<vector<int>>&dp)
{
    if(j == 0) return i;
    if(i == 0) return j;

    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]) return dp[i][j] = Editdistance(s1,s2,i-1,j-1,dp);
    else return dp[i][j] = 1 + min({Editdistance(s1,s2,i-1,j-1,dp) , Editdistance(s1,s2,i-1,j,dp) , Editdistance(s1,s2,i,j-1,dp)});
}
*/

//Tabulation
int editDistance(string &s, string &t, int n, int m)
{
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;

            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else 
            {
                dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}

//Space Optimization

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    if(word1 == word2) return 0;
    // return Editdistance(word1,word2,n,m,dp);

    vector<int>prev(m+1,0) , curr(m+1,0);

    // for(int i=0;i<=n;i++) curr[0] = i;
    for(int j=0;j<=m;j++) prev[j] = j;

    for(int i=1;i<=n;i++)
    {
        curr[0] = i;
        for(int j=1;j<=m;j++)
        {
            if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1 + min({prev[j-1] , prev[j] , curr[j-1]});  
        }

        prev = curr;
    }

    return prev[m];
}

int main()
{
    string s = "horse";
    string t = "ros";
    int n = s.length();
    int m = t.length();
    // memset(dp, -1, sizeof(dp));
    // cout<< editDistance(s, t, n - 1, m - 1);
    memset(dp, 0, sizeof(dp));
    cout<< editDistance(s, t, n, m);

    return 0;
}