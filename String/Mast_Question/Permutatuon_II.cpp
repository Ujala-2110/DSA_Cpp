// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// link -> [https://leetcode.com/problems/permutations-ii/]

#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<int> &nums, vector<vector<int>> &output, int idx)
{
    if (idx == size(nums))
    {
        output.push_back(nums);
        return;
    }

    unordered_set<int> visited; // Track visited elements to avoid duplicates
    for (int i = idx; i < size(nums); ++i)
    {
        if (visited.count(nums[i]) > 0)
            continue;
        visited.insert(nums[i]);

        swap(nums[i], nums[idx]);
        generatePermutations(nums, output, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> output;
    // sort(begin(nums), end(nums));
    generatePermutations(nums, output, 0);
    return output;
}