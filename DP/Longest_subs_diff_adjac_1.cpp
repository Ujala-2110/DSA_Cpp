#include <bits/stdc++.h>
using namespace std;

int longestSubseqWithDiffOne(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
    dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j]+1 || arr[i] == arr[j] - 1)
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = *max_element(dp, dp + n);
    return result;
}

int main()
{
    // Longest subsequence with one difference is
    // {1, 2, 3, 4, 3, 2}
    int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSubseqWithDiffOne(arr, n);
    return 0;
}