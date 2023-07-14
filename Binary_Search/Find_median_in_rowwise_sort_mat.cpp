#include <bits/stdc++.h>
using namespace std;

// Algorithm:  

// First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found by comparing the first element of each row, and similarly, the maximum element can be found by comparing the last element of each row.
// Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than or equal to our mid. And accordingly change the min or max.
// For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than or equal to that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.

int small_equal_to_mid(vector<int> &arr, int mid)
{
    int l = 0;
    int h = arr.size() - 1;

    while (l <= h)
    {
        int md = (l + h) >> 1;

        if (arr[md] <= mid) l = md + 1;
        else  h = md - 1;
    }

    return l;
}

int median(vector<vector<int>> &mat, int r, int c)
{
    // code here
    int low = 1;
    int high = 1e9;
    // int low = INT_MAX;
    // int high = INT_MIN;
    // for(int i = 0 ; i < r; i++) low = min(low, mat[i][0]);
    // for(int i = 0 ; i < r; i++) high = max(high, mat[i][c-1]);

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int cnt = 0;

        for (int i = 0; i < r; i++)
        {
            cnt += small_equal_to_mid(mat[i], mid);
            // cnt+=(upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin());
        }

        if (cnt <= (r * c) / 2) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

// Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
// Auxiliary Space: O(1) 

int main()
{
    int r = 3, c = 3;

    vector<vector<int>> mat{{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout<<median(mat,r,c);
    return 0;
}