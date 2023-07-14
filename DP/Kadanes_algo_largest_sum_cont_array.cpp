#include <bits/stdc++.h>
using namespace std;

// Brute Force
/*
int maxSubArraySum(int arr[], int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }
    return ans;
}
*/
// O(n^2)
// S.C-> O(1)

// Kadane's Algorithm
/*
int maxSubArraySum(int arr[], int n)
{
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // Purana family sabko add karte chalega ki agar kahin aage bahut bada positive mil jaye.
        ans = max(ans, sum); // Overall best store karke rakhega

        if(sum < 0) sum = 0; // Agar negative ho gya sum to naya family start kar lega
    }
    return ans;
}
*/
// O(n)
// S.C-> O(1)

int maxSubArraySum(int arr[], int n)
{
    int ans = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > ans)
        {
            ans = sum;
            end = i;
        }

        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }
    }
    cout << "Starting and final indexes of maximum sum subarray is " << start << " " << end << "\n";
    return ans;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

// Q-> Maximum difference of zeros and ones in binary string -> Kadane's algorithm

// Q-> Maximum product subarray