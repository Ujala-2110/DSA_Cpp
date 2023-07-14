#include <bits/stdc++.h>
using namespace std;

//Recursion
int func(int ind1, int ind2, string &X , string &Y)
{
    if(ind1 == 0 || ind2 == 0) return 0;
    
    if(X[ind1-1] == Y[ind2-1]) return 1+func(ind1-1,ind2-1,X,Y);
    return max(func(ind1-1,ind2,X,Y) , func(ind1,ind2-1,X,Y));
}

int lcs(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    
	return func(n,m,X,Y);
}

//TC -> O(2^n * 2^m)

//Memoization (It has two states so it takes a 2d dp)
int func(int ind1, int ind2, string &X , string &Y,vector<vector<int>>&dp)
{
    if(ind1 == 0 || ind2 == 0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(X[ind1-1] == Y[ind2-1]) return dp[ind1][ind2] = 1+func(ind1-1,ind2-1,X,Y,dp);
    return dp[ind1][ind2] = max(func(ind1-1,ind2,X,Y,dp) , func(ind1,ind2-1,X,Y,dp));
}

//TC-> O(n*m)
//SC-> O(n*m) + O(n+m) ->Ass

int lcs(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return func(n,m,X,Y,dp);
}

//Tabulation
//In this case as writing base case for negative index will be little difficult so we shift the index

int lcs(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int ind1=1;ind1<=n;ind1++)
    {
        for(int ind2=1;ind2<=m;ind2++)
        {
            if(X[ind1-1] == Y[ind2-1])  dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
            else dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}

//Space Optimization
int lcs(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    vector<int>prev(m+1,0) , curr(m+1,0);
    for(int ind1=1;ind1<=n;ind1++)
    {
        for(int ind2=1;ind2<=m;ind2++)
        {
            if(X[ind1-1] == Y[ind2-1])  curr[ind2] = 1+prev[ind2-1];
            else curr[ind2] = max(prev[ind2] , curr[ind2-1]);
        }
        prev = curr;
    }
    
    return prev[m];
}

//Space Optimization upto 1 array
int lcs(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    vector<int> cur(m+1, 0);
    int prev;
    for(int ind1=1; ind1<=n; ind1++){
        prev = 0;
        for(int ind2=1; ind2<=m; ind2++){
            int prev1 = cur[ind2];
            if(X[ind1-1]==Y[ind2-1]){
                cur[ind2] = 1 + prev;
            }else{
                cur[ind2] = max(cur[ind2-1], cur[ind2]);
            }
            prev = prev1;
        }
    }
    return cur[m];
}


// Q-> Minimum number of deletions and insertions to convert a string to other.
//  ans -> (n-lcs(s1,s2) + (m-lcs(s1,s2))); n->s1.length() , m->s2.length();