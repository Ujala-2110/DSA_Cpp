#include <bits/stdc++.h>
using namespace std;

// Hashing Method
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp = x - arr[i];

        if (s.find(temp) != s.end())
            return true;

        s.insert(arr[i]);
    }
    return false;
}

//Two pointer method
// bool hasArrayTwoCandidates(int arr[], int n, int x)
// {
//     sort(arr, arr + n);
//     int l = 0;
//     int h = n - 1;

//     while (l < h)
//     {
//         if (arr[l] + arr[h] == x)
//             return true;
//         else if ((arr[l] + arr[h]) > x)
//             h--;
//         else
//             l++;
//     }
//     return false;
// }

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(int);
    int x = 16;

    if (hasArrayTwoCandidates(arr, n, x))
        cout << "Two number is present whose sum is x";
    else
        cout << "Two number is not present whose sum is x";
    return 0;
}