#include<bits/stdc++.h>
using namespace std;

void Print_scsuper(string &s1,string &s2)
{
    int n = s1.size();
    int m = s2.size();

    int L[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    string ans = "";
    int i = n;
    int j = m;
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            i--;
            j--;
        }

        else if(L[i-1][j] > L[i][j-1])
        {
            ans += s1[i-1];
            i--;
        }
        else
        {
            ans += s2[j-1];
            j--;
        }
    }

    while(i>0)
    {
        ans += s1[i-1];
        i--;
    }
    while(j>0)
    {
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(),ans.end());
    for(int l=0;l<ans.size();l++)
    cout<<ans[l];
}

int main()
{
    string s1 = "groot";
    string s2 = "brute";

    Print_scsuper(s1, s2);
    return 0;
}