// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// link -> [https://leetcode.com/problems/permutations/description/]

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &s, int index, vector<vector<int>> &res)
{
    if (index == s.size())
    {
        res.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> res;
    solve(nums, 0, res);

    return res;
}