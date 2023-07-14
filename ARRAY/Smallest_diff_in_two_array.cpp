#include <bits/stdc++.h>
using namespace std;

// Bruteforce
// int findSmallestDifference(int A[], int B[], int m, int n)
// {
//     int ans = INT_MAX;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ans = min(ans, abs(A[i] - B[j]));
//         }
//     }

//     return ans;
// }

//
// int findSmallestDifference(int A[], int B[], int m, int n)
// {
//     sort(A, A + m);
//     sort(B, B + n);
//     int ans = INT_MAX;

//     if (A[0] < B[0])
//     {
//         int i = 0;
//         while (A[i] < B[0] && i < m)
//         {
//             ans = min(ans, abs(A[i] - B[0]));
//             i++;
//         }

//         int j = 0;
//         while (i < m && j < n)
//         {
//             ans = min(ans, abs(A[i] - B[j]));
//             i++;
//             j++;
//         }
//     }
//     else
//     {
//         int i = 0;
//         while (B[i] < A[0] && i < n)
//         {
//             ans = min(ans, abs(B[i] - A[0]));
//             i++;
//         }

//         int j = 0;
//         while (i < n && j < m)
//         {
//             ans = min(ans, abs(B[i] - A[j]));
//             i++;
//             j++;
//         }
//     }

//     return ans;
// }

int findSmallestDifference(int A[], int B[], int m, int n)
{
    sort(A, A + m);
    sort(B, B + n);

    int a = 0, b = 0;
    int res = INT_MAX;

    while (a < m && b < n)
    {
        res = min(res, abs(A[a] - B[b]));

        if (A[a] < B[b]) a++;
        else b++;
    }

    return res;
}

int main()
{
    int A[] = {3, 2, 8};
    int B[] = {4, 6, 8, 1, 0};

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    cout << findSmallestDifference(A, B, m, n);

    return 0;
}