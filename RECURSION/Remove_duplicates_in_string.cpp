#include <bits/stdc++.h>
using namespace std;

string Remove_Duplicates(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = Remove_Duplicates(s.substr(1));

    if (ch == ans[0])
        return ans;

    return (ch + ans);
}

int main()
{
    string a = "aaaabbbeeecdddd";
    cout << Remove_Duplicates(a);
    return 0;
}