
// Maximum distance between two same elements of an array

#include <bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n)
{
    unordered_map<int, int> mp;

    int mx_dist = 0;
    for (int i = 0; i < n; i++)
    {
        // If this is first occurrence of element, insert its
        // index in map
        if (mp.find(arr[i]) == mp.end())
            mp[arr[i]] = i;

        // Else update max distance
        else
            mx_dist = max(mx_dist, i - mp[arr[i]]);
    }

    return mx_dist;
}


int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxDistance(arr, n);
    return 0;
}