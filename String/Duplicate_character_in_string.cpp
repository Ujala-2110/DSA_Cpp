#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int n = str.length();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[str[i]]++;

    for (auto &it : mp)
    {
        if (it.second > 1)
       cout << it.first << ", count = " << it.second<< "\n";
    }
    return 0;
}