#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int dp[N][N];
//Recursion
/*
int lcs(string &X, string &Y, int m, int n)
{
    if(m==0 || n==0) return 0;

    if (X[m - 1] == Y[n - 1])
    return (1 + lcs(X, Y, m - 1, n - 1));

    else 
    return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
*/

//Memoization (It has two states so it takes a 2d dp)
/*
int lcs(string &X, string &Y, int m, int n)
{
    if (m == 0 || n == 0) return 0;

    if (dp[m][n] != -1) return dp[m][n];  //step -> 2

    if (X[m - 1] == Y[n - 1])
    return dp[m][n] = (1 + lcs(X, Y, m - 1, n - 1)); //step -> 3

    else
    return dp[m][n] = max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n)); //step -> 3
}
*/

//Tabulation

int lcs(string &X, string &Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    // Following steps build L[m+1][n+1] in bottom up fashion. Note
    // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] 
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
    return L[m][n];
}


int main()
{
    string X = "geek";
    string Y = "eke";
    memset(dp, -1, sizeof(dp));
    int m = X.length();
    int n = Y.length();

    cout << "Length of Shortest Common Supersequence is " <<  m + n - lcs(X, Y, m, n);//becuase lcs gets counted 2 times

    return 0;
}

// Q-> Minimum number of deletions and insertions to convert a string to other.
//  ans -> (n-lcs(s1,s2) + (m-lcs(s1,s2))); n->s1.length() , m->s2.length();