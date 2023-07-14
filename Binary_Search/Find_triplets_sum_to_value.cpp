#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++)
        {
            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << "Triplet is " << A[i] << ", " << A[j] << ", " << A[k];
                    return true;
                }
            }
        }
    }
    return false;
}

// Time Complexity: O(n3).
// There are three nested loops traversing the array, so the time complexity is O(n^3)
// Space Complexity: O(1).
// As no extra space is required.

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);
    for (int i = 0; i < arr_size - 2; i++)
    {
        l = i + 1;
        r = arr_size - 1;
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == sum)
            {
                printf("Triplet is %d, %d, %d", A[i], A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}

// Time complexity: O(N^2).
// There are only two nested loops traversing the array, so time complexity is O(n^2).
// Two pointers algorithm takes O(n) time and the first element can be fixed using another nested traversal.
// Space Complexity: O(1).
// As no extra space is required.

bool find3Numbers(int A[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size - 2; i++)
    {
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i], A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
    return false;
}

// Time complexity: O(N^2) 
// Auxiliary Space: O(N), since n extra space has been taken.

int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A, arr_size, sum);
    return 0;
}
