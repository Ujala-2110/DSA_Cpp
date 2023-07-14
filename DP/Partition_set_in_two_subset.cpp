// A Recursive C++ program to solve minimum sum partition problem.
#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal)
{
    // If we have reached last element. Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated. Return absolute difference
    // of two sums.
    if (i == 0)
    return abs((sumTotal - sumCalculated) - sumCalculated);

    // For every item arr[i], we have two choices
    // (1) We do not include it in first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(
        findMinRec(arr, i - 1, sumCalculated + arr[i - 1],  sumTotal),
        findMinRec(arr, i - 1, sumCalculated, sumTotal));
}
*/



// Memoization
/*
int findMinRec(int arr[], int i, int sumCalculated,int sumTotal,vector<vector<int>>&dp)
{
    if (i == 0) return abs((sumTotal - sumCalculated) - sumCalculated);

    if(dp[i][sumCalculated] != -1) return dp[i][sumCalculated];

    return dp[i][sumCalculated] =  min(
        findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal,dp),
        findMinRec(arr, i - 1, sumCalculated, sumTotal,dp));
}

int findMin(int arr[], int n)
{
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
    sumTotal += arr[i];

    vector<vector<int>>dp(n+1,vector<int>(sumTotal+1,-1));
    return findMinRec(arr, n, 0, sumTotal,dp);
}
*/

// int minSubsetSumDifference(vector<int>& arr, int n)
// {
//     int sum = 0;
//     for(auto it : arr) sum += it;
//     vector<vector<int>>dp(n, vector<int>(sum+1,0));
//     int s = 0;
// //     return func(n-1,sum,s,arr,dp);
    
//     for(int s=0;s<=sum;s++) dp[0][s] = abs((sum - s) - s);
    
//     for(int ind=1;ind<n;ind++)
//     {
//         for(int s=sum;s>=0;s--)
//         {
//             dp[ind][s] = min(dp[ind-1][s+arr[ind]], dp[ind-1][s]);
//         }
//     }

//      return dp[n-1][0];
// }

// Tabulation
int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= sum; i++) dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= sum; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs((sum - s1) - s1));
        }
    }

    return mini;
}
int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "The minimum difference between two sets is " << findMin(arr, n);
    cout << "The minimum difference between two sets is " << minDifference(arr, n);
    return 0;
}
