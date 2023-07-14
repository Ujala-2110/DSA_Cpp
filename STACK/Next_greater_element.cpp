#include <bits/stdc++.h>
using namespace std;
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define vl vector<int>
#define pb push_back

void NGE(int *arr, int n)
{
    vector<int> v;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                v.pb(arr[j]);
                break;
            }
        }
        if (j == n)
            v.pb(-1);
    }

    for (auto &it : v)
        cout << it << " ";

    // for (auto it = v.begin();it != v.end(); it++)
    //     cout << *it << " ";

    // int next, i, j;
    // for (i = 0; i < n; i++)
    // {
    //     next = -1;                          //Nice approach
    //     for (j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] < arr[j])
    //         {
    //             next = arr[j];
    //             break;
    //         }
    //     }
    //     cout << arr[i] << " -- "
    //          << next << endl;
    // }
}

int main()
{
    int arr[] = {4,5,2,25};
    int n = sizeof(arr) / sizeof(int);

    NGE(arr, n);
    return 0;
}