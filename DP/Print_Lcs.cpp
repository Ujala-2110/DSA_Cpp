#include <bits/stdc++.h>
using namespace std;

void Print_lcs(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int len = L[m][n];

    string ans = "";
    for (int i = 0; i < len; i++)
        ans += "$";

    int index = len - 1;
    int i = m;
    int j = n;


    // TC -> O(n+m) vvvvvv
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    cout << ans << "\n";
}

//TC-> O(n*m) tabulation

int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";

    Print_lcs(s1, s2);
    return 0;
}