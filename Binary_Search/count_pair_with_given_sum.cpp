#include <bits/stdc++.h>
using namespace std;

//Naive way
int getPairsCount(int arr[], int n, int sum)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;

    return count;
}
// Time Complexity: O(n2), traversing the array for each element
// Auxiliary Space: O(1)

int getPairsCount(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int x = 0, c = 0, y, z;
    for (int i = 0; i < n - 1; i++) {
        x = k - arr[i];
 
        // Lower bound from i+1
        int y = lower_bound(arr + i + 1, arr + n, x) - arr;
 
        // Upper bound from i+1
        int z = upper_bound(arr + i + 1, arr + n, x) - arr;
        c = c + z - y;
    }
    return c;
}
// Time Complexity: O(n * log(n) ), applying binary search on each element
// Auxiliary Space: O(1)

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(k - arr[i]) != m.end()) {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}
// Time Complexity: O(n), to iterate over the array
// Auxiliary Space: O(n), to make a map of size n

int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
    return 0;
}
