// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList
// The second part of this problem can be found here.

// Note: If no possible way to transform sequence from startWord to targetWord return 0

// Example 1:

// Input:
// wordList = {"des","der","dfr","dgt","dfs"}
// startWord = "der", targetWord= "dfs",
// Output:
// 3
// Explanation:
// The length of the smallest transformation
// sequence from "der" to "dfs" is 3
// i,e "der" -> "dfr" -> "dfs".

#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wl)
{
    int n = wl.size();
    int m = wl[0].size();

    set<string> st(wl.begin(), wl.end()); //To check whether word exist or not
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    st.erase(startWord);

    // n*m*26*log(n)
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord) return steps;

        // m*26*log(n)
        for (int i = 0; i < m; i++)
        {
            //hat
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                //aat , bat , cat , dat ------------------zat and if word exist then put it in queue and increase the level
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word); // so that we can't considere it again
                    q.push({word, steps + 1});
                }
            }

            //restore the original word
            word[i] = original;
        }
    }

    return 0;
}