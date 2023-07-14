// //Variation of lis

// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

#include <bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1) return false;

    int fr = 0;
    int sc = 0;

    while (fr < s1.size())
    {
        if (s1[fr] == s2[sc] && sc < s2.size())
        {
            fr++;
            sc++;
        }

        else
            fr++;
    }

    if (fr == s1.size() && sc == s2.size()) return true;
    return false;
}

//make the "compare" function as static, because sort() function takes static function pointer as an argument.
static bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &words)
{

    sort(words.begin(), words.end(), comp);
    int n = words.size();
    vector<int> dp(n, 1);

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (check(words[i], words[prev])) dp[i] = max(dp[i], 1 + dp[prev]);
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << longestStrChain(words);

    return 0;
}