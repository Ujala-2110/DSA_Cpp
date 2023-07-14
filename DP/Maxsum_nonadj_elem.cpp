#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
int FindMaxSum(vector<int> &arr, int ind)
{
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;

    int pick = arr[ind] + FindMaxSum(arr, ind - 2);
    int nonpick = 0 + FindMaxSum(arr, ind - 1);

    return max(pick, nonpick);
}
*/


//Memoization
/*
int FindMaxSum(vector<int> &arr, int ind, vector<int> &dp)
{
    if (ind == 0) return arr[ind];
    if (ind < 0)  return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + FindMaxSum(arr, ind - 2,dp);
    int nonpick = 0 + FindMaxSum(arr, ind - 1,dp);

    return dp[ind] = max(pick, nonpick);
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << FindMaxSum(arr, arr.size() - 1, dp);
}
*/

//Tabulation
int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int n = arr.size();

    // vector<int> dp(n);
    // dp[0] = arr[0];

    // for (int i = 1; i < n; i++)
    // {
    //     int pick = arr[i];
    //     if (i > 1)
    //     pick += dp[i - 2];

    //     int nonpick = 0 + dp[i - 1];

    //     dp[i] = max(pick, nonpick);
    // }

    // cout<<dp[n-1];

    //Space optimization
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        pick += prev2;

        int nonpick = prev;

        int curi = max(pick, nonpick);
        prev2 = prev;
        prev = curi;
    }

    cout << prev;
    return 0;
}