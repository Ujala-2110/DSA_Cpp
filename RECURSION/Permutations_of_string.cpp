#include <bits/stdc++.h>
using namespace std;

void Permute(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string rest = str.substr(0, i) + str.substr(i + 1); //I can take out any character from a string using this. 
        Permute(rest, ans + ch);
    }
}

int main()
{
    Permute("ABC", ""); 
    return 0;
}

// Method->2
// Find the next lexicographically
// greater permutation of a word

// #include <algorithm>
// #include <iostream>

// using namespace std;

// int main()
// {
//     string s = {"gfg"};
//     bool val = next_permutation(s.begin(), s.end());
//     if (val == false)
//         cout << "No Word Possible" << endl;
//     else
//         cout << s << endl;
//     return 0;
// }
