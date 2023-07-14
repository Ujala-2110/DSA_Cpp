// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 
// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.

#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];

    for (int i = 1; i < N; i++)
    {
        string s1 = dict[i - 1];
        string s2 = dict[i];

        int sz = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < sz; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> indegree(K, 0);

    for (int i = 0; i < K; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < K; i++)
        if (indegree[i] == 0)
            q.push(i);

    string order = "";

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        order += char(f + 'a');

        for (auto it : adj[f])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return order;
}

//When the order will not be possible how will u figure that out??
// ==>  1. when there will be a cyclic dependency (abc , bat , ade)
    //  2. If everything is matching and the larger string is before shorter string in sorted alien dictionary (abcd , abc)

// leetcode -> 953. Verifying an Alien Dictionary