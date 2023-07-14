#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int h[N];

// Recursion
/*
int Mincost(int n)
{
    if (n == 0) return 0;
    if (n == 1) return abs(h[1] - h[0]);
    return min((Mincost(n - 1) + abs(h[n] - h[n - 1])), (Mincost(n - 2) + abs(h[n] - h[n - 2])));

    // int cost = INT_MAX;
    //way 1
    // cost = min(cost, Mincost(n - 1) + abs(h[n] - h[n - 1]));
    // //way 2
    // if (n > 1)
    // cost = min(cost, Mincost(n - 2) + abs(h[n] - h[n - 2]));
    // return cost


}
*/

// Memoization
// parameter that are changed in function in simple way are called sates in this case there is only one parameter
// that is changing (n) . so it's state is one and so we required 1D dp to solve it
int Mincost(vector<int> &dp, int n)
{
    if (n == 0) return 0;
    if (n == 1) return abs(h[1] - h[0]);

    if(dp[n] != -1) return dp[n]; // step 2

    return dp[n] = min((Mincost(dp,n - 1) + abs(h[n] - h[n - 1])), (Mincost(dp,n - 2) + abs(h[n] - h[n - 2]))); // step 3


    // int cost = INT_MAX;
    // if (dp[n] != -1) return dp[n]; //step 2
    // cost = min(cost, Mincost(dp,n - 1) + abs(h[n] - h[n - 1]));

    // if (n > 1)
    // cost = min(cost, Mincost(dp,n - 2) + abs(h[n] - h[n - 2]));
    // return dp[n] = cost; //step 3
}

//Tabulation
/*
int Mincost(vector<int> &dp,int n)
{
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i=2;i<=n;i++)
    {
        dp[i] = min((dp[i-1] + abs(h[i] - h[i - 1])), (dp[i-2] + abs(h[i] - h[i - 2])));
    }

    return dp[n];
}
*/
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1); //step 1
    for (int i = 0; i < n; i++)
    cin >> h[i];

    // cout << Mincost(n - 1); // For recursion
    cout << Mincost(dp, n - 1);
    return 0;
}