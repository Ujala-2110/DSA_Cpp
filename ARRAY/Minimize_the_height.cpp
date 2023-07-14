// Given heights of n towers and a value k. We need to either increase or decrease the height of every tower by k
//  (only once) where k > 0. The task is to minimize the difference between the heights of the longest and
//  the shortest tower after modifications and output this difference.

#include <bits/stdc++.h>
using namespace std;

// tc - 5,7,9,15 k = 3
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n); // because adjacent elements can give minimum difference
    int ans = arr[n - 1] - arr[0];

    int mn, mx;
    mn = arr[0];
    mx = arr[n - 1];

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i + 1] >= k) //(Height can't be negative)
        {
            mn = min(arr[0] + k, arr[i + 1] - k);
            mx = max(arr[i] + k, arr[n - 1] - k);
            ans = min(ans, mx - mn);
        }
    }
    return ans;
}

int main()
{
    int k = 6, n = 6;
    int arr[n] = {7, 4, 8, 8, 8, 9};
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}