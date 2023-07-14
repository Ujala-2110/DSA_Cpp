#include <bits/stdc++.h>
using namespace std;

//Move x to the last
string Move_X(string s)
{
    if (s.size() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = Move_X(s.substr(1));

    if (ch == 'x')
        return ans + ch;

    return (ch + ans);
}

int main()
{
    string a = "axxbdxcefxhix";
    cout << Move_X(a);
    return 0;
}