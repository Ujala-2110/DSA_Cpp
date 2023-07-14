#include <bits/stdc++.h>
using namespace std;

// Tabulation
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;

            else if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }

    return result;
}

int main()
{
    string X = "STONE";
    string Y = "LONGEST";
    int n = X.length();
    int m = Y.length();
    // memset(dp,-1,sizeof(dp));
    cout << "Length of longest CommonSubstr is " << longestCommonSubstr(X, Y, n, m);

    return 0;
}