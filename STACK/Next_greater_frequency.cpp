#include <bits/stdc++.h>
using namespace std;

void NGF(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        int next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (mp[arr[i]] < mp[arr[j]])
            {
                next = arr[j];
                break;
            }
        }
        cout << next << " ";
    }
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    NGF(arr, n);
    return 0;
}