#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
bool isSubsetSum(int set[], int n, int sum)
{
    if (n == 0) return set[0] == sum;
    if (sum == 0) return true;

    // If last element is greater than sum, then ignore it
    if (set[n - 1] > sum) return isSubsetSum(set, n - 1, sum);

    else, check if sum can be obtained by any of the following:
	(a) including the last element
	(b) excluding the last element 
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
*/

// Memoization
/*
bool isSubsetSum(int set[], int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0) return true;
    if (n == 0) return return set[0] == sum;

    if (dp[n][sum] != -1) return dp[n][sum]; //step -> 2

    if (set[n - 1] > sum)
    return dp[n][sum] = isSubsetSum(set, n - 1, sum, dp);

    return dp[n][sum] = isSubsetSum(set, n - 1, sum, dp) || isSubsetSum(set, n - 1, sum - set[n - 1], dp);
}
*/

// Tabulation
bool isSubsetSum(int set[], int n, int sum, vector<vector<bool>> &dp)
{
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= sum; i++) dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            dp[i][j] = dp[i - 1][j];

            else
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    return dp[n][sum];
}

int main()
{
    int set[] = {3 ,6 , 10};
    int sum = 15;
    int n = sizeof(set) / sizeof(set[0]);
    // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1)); //step -> 1
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1)); //step -> 1
    // if (isSubsetSum(set, n, sum) == true) //Recursion
    if (isSubsetSum(set, n, sum, dp) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}


//Space Optimization
/*
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<int>prev(k+1,0),cur(k+1,0);
    for(int i = 0 ; i<=n;i++) prev[0] = 1;
    for(int j = 1 ; j<=k;j++) prev[j] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int nottake = prev[j];
            int take = 0;
            if(arr[i-1] <= j) take = prev[j-arr[i-1]];
            cur[j] = take || nottake;
        }
        prev = cur;
    }
    return prev[k];
}
*/