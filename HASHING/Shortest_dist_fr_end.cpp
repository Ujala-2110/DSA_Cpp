#include <bits/stdc++.h>
using namespace std;

int find_maximum(int arr[], int n, int k)
{
    unordered_map<int, int> b;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        int d = min(i + 1, n - i);
        if (b.find(x) == b.end())
            b[x] = d;

        else
        { /* if duplicates are found, b[x]
            is replaced with minimum of the
            previous and current position's
            shortest distance*/
            b[x] = min(d, b[x]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        if (x != k - x && b.find(k - x) != b.end())
            ans = min(max(b[x], b[k - x]), ans);
    }

    return ans;
}

int main()
{
    int a[] = {3, 5, 8, 6, 7};
    int K = 11;
    int n = sizeof(a) / sizeof(a[0]);
    cout << find_maximum(a, n, K) << endl;
    return 0;
}