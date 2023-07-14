// Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. 
// Write a function that returns true if array contains duplicates within k distance.
// Examples: 

// Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
// Output: false
// All duplicates are more than k distance away.

// Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
// Output: true
// 1 is repeated at distance 3.

// Input: k = 3, arr[] = {1, 2, 3, 4, 5}
// Output: false

// Input: k = 3, arr[] = {1, 2, 3, 4, 4}
// Output: true


#include <bits/stdc++.h>
using namespace std;

bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    unordered_set<int> myset;

    for (int i = 0; i < n; i++)
    {
        if (myset.find(arr[i]) != myset.end())
            return true;

        myset.insert(arr[i]);

        // Remove the k+1 distant item
        if (i >= k)
            myset.erase(arr[i - k]);
    }
    return false;
}

int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinK(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}
