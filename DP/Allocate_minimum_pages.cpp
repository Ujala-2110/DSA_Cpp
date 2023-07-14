#include <bits/stdc++.h>
using namespace std;

//Binary Search
bool isPossible(int arr[],int n, int m , int barrier)
{
    int student = 1;
    int curr_sum = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > barrier) return false;

        if(curr_sum + arr[i] > barrier)
        {
            student++;
            curr_sum = arr[i];
            if (student > m) return false;
        }

        else curr_sum += arr[i];
    }

    return true;
}

int findPages(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m) return -1;

    for (int i = 0; i < n; i++) sum += arr[i];

    // initialize start as lowest value and end as total pages
    int start = arr[n-1], end = sum;
    int result = INT_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            // update result to current distribution
            // as it's the best we have found till now.
            result = mid;

            // as we are finding minimum and books
            // are sorted so reduce end = mid -1
            // that means
            end = mid - 1;
        }

            // if not possible means pages should be
            // increased so update start = mid + 1
        else start = mid + 1;
    }
    return result;
}

// Time Complexity: O(N*log (M – max)), where N is the number of different books , max denotes the maximum number of pages 
// from all the books and M denotes the sum of number of pages of all different books
// Auxiliary Space: O(1)

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2;

    cout << "Minimum number of pages = " << findPages(arr, n, m) << endl;
    return 0;
}