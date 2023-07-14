//Boolean Parenthesization
// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Example 1:

// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates 
// to true in 4 ways ((T|T)&(F^T)), 
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

#include <bits/stdc++.h> 
using namespace std;

#define ll long long
const int mod = 1e9+7;
//Recursion
int func(int i, int j, string &exp,bool isTrue)
{
    if(i > j) return 0;

    if(i == j)
    {
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    int ways = 0;

    for(int ind = i+1; ind <= j-1 ; ind += 2)
    {
        int lt = func(i,ind-1,exp,1);
        int lf = func(i,ind-1,exp,0);
        int rt = func(ind+1,j,exp,1);
        int rf = func(ind+1,j,exp,0);

        if(exp[ind] == '&'){
            if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
        }

        else if(exp[ind] == '|'){
            if(isTrue) ways = (ways + (lt * rt) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod) % mod;
        }

        else{
            if(isTrue) ways = (ways + (lt * rf) % mod + (lf*rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod + (lt*rt) % mod) % mod;
        }

    }
    return ways;
}


//Memoization
ll func(int i, int j, string &exp,bool isTrue,vector<vector<vector<int>>>&dp)
{
    if(i > j) return 0;

    if(i == j)
    {
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;

    for(int ind = i+1; ind <= j-1 ; ind += 2)
    {
        ll lt = func(i,ind-1,exp,1,dp);
        ll lf = func(i,ind-1,exp,0,dp);
        ll rt = func(ind+1,j,exp,1,dp);
        ll rf = func(ind+1,j,exp,0,dp);

        if(exp[ind] == '&'){
            if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
        }

        else if(exp[ind] == '|'){
            if(isTrue) ways = (ways + (lt * rt) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod) % mod;
        }

        else{
            if(isTrue) ways = (ways + (lt * rf) % mod + (lf*rt) % mod) % mod;
            else ways = (ways + (lf*rf) % mod + (lt*rt) % mod) % mod;
        }

    }
        return dp[i][j][isTrue] = ways % mod;
}

int evaluateExp(string & exp) {
    
    int n = exp.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return func(0,n-1,exp,1,dp) % mod;
}

//Tabulation
int evaluateExp(string & exp) {

    int n = exp.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    // return func(0,n-1,exp,1,dp) % mod;

    for(int i=0;i<=n-1;i++) dp[i][i][1] = (exp[i] == 'T');
    for(int i=0;i<=n-1;i++) dp[i][i][0] = (exp[i] == 'F');

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=n-1;j++)
        {
            if(i == j) continue;
            
            for(int isTrue = 0; isTrue<=1;isTrue++)
            {
                ll ways = 0;

                for(int ind = i+1; ind <= j-1 ; ind += 2)
                {
                    ll lt = dp[i][ind-1][1];
                    ll lf = dp[i][ind-1][0];
                    ll rt = dp[ind+1][j][1];
                    ll rf = dp[ind+1][j][0];

                    if(exp[ind] == '&'){
                        if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
                        else ways = (ways + (lf*rf) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
                    }

                    else if(exp[ind] == '|'){
                        if(isTrue) ways = (ways + (lt * rt) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
                        else ways = (ways + (lf*rf) % mod) % mod;
                    }

                    else {
                        if (isTrue)
                        ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                        else
                        ways = (ways + (lf * rf) % mod + (lt * rt) % mod) % mod;
                    }
                }
                
                dp[i][j][isTrue] = ways % mod;
            }
        }
    }

    return dp[0][n-1][1];
}

























































