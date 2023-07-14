// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

#include <bits/stdc++.h>
using namespace std;


// 1. Create a new string by concatenating given string, a special character and reverse of given string, then we will get LPS array for this concatenated string
// 2. Minimum number of character needed to make the string a palindrome is length of the input string minus last entry of our lps array.

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int minChar(string str)
{
    string s = str;
    string rev = str;
    reverse(rev.begin(), rev.end());
    s += '$';
    s += rev;

    vector<int> ans;
    ans = prefix_function(s);

    int n = str.size();
    return (n - ans[ans.size() - 1]);
}

int main()
{
    string S = "abc";
    cout<<minChar(S);
    return 0;
}