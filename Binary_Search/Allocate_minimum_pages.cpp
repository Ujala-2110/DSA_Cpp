#include <bits/stdc++.h>
using namespace std;

bool is_possible(int arr[], int n, int m, int barrier)
{
    int std = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > barrier) return false;

        if (curr_sum + arr[i] > barrier)
        {
            std++;
            curr_sum = arr[i];
            if (std > m) return false;
        }

        else curr_sum += arr[i];
    }

    return true;
}

// Function to find minimum number of pages.
int findPages(int arr[], int n, int m)
{
    if (n < m) return -1;

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int l = arr[n - 1], h = sum;
    int res = INT_MAX;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (is_possible(arr, n, m, mid))
        {
            res = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int m;
    cin >> m;
    cout << findPages(A, n, m);

    return 0;
}
