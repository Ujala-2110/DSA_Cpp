// Given an array of positive integers. Find the maximum length of Bitonic subsequence.
// A subsequence of array is called Bitonic if it is first increasing, then decreasing.

#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
            dp1[i] = max(dp1[i], 1 + dp1[prev]);
        }
    }
    //Longest incresing subsequence from starting 

    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (nums[prev] < nums[i])
            dp2[i] = max(dp2[i], 1 + dp2[prev]);
        }
    }
    //Longest incresing subsequence from ending 

    int maxi = 1;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, dp1[i] + dp2[i] - 1);

    return maxi;
}

int main()
{
    vector<int> nums = {1, 2, 5, 3, 2};

    cout << LongestBitonicSequence(nums);

    return 0;
}