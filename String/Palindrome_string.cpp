#include <bits/stdc++.h>
#include <string>
using namespace std;

int palindrome(string str)
{
    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
            return 0;
    }
    return 1;
}

int main()
{
    string str, s;
    cin >> str;
    if (palindrome(str))
        cout << "It is a palindrome";
    else
        cout << "It is not a palindrome";
    return 0;
}
// int main()
// {
//     string str, s;
//     cin >> str;
//     s = str;                                    //*****
//     reverse(str.begin(), str.end());
//     if (s == str)
//         cout << "It is a palindrome";
//     else
//         cout << "It is not a palindrome";
//     return 0;
// }