#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> a(N);
int dp[N];

//Recursion
/*
int lis(int i)
{
    int ans = 1; //minimum length of subsequence can be 1 (The number itself)
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, lis(j) + 1);
        }
    }
    return ans;
}
*/

//Memoization

int lis(int i)
{
    if(dp[i] != -1) return dp[i];
    int ans = 1; //minimum length of subsequence can be 1 (The number itself)
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}
//O(N^2)


int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis(i));

    cout << ans;
    return 0;
}