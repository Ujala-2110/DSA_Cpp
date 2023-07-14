#include <bits/stdc++.h>
using namespace std;

void top3Repeated(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Initialize first value of each variable
    // of Pair type is INT_MIN
    pair<int, int> x, y, z;
    x.first = y.first = z.first = INT_MIN;

    for (auto curr : freq)
    {
        if (curr.second > x.first)
        {
            z = y;
            y = x;
            x.first = curr.second;
            x.second = curr.first;
        }

        else if (curr.second > y.first)
        {
            z = y;
            y.first = curr.second;
            y.second = curr.first;
        }

        else if (curr.second > z.first)
        {
            z.first = curr.second;
            z.second = curr.first;
        }
    }

    cout << "Top 3 repeated elements are " << x.second << " " << y.second << " " << z.second << "\n";
}

// Time Complexity : O(n) 
// Auxiliary Space : O(n)

int main()
{
    int arr[] = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    top3Repeated(arr, n);
    return 0;
}

// Algorithm

// 1) Initialize the largest three elements
//    as Minimum value.
//     x.first = y.first = z.first = Minus-Infinite

// 2) Iterate through all elements of the
//    hash table freq.
//    a) Let current array element be p.
//    b) If (fre[p] !=0 && fre[p] > x.first)
//       {
//           // This order of assignment is important
//           z = y
//           y = x
//           x.first = fre[p]
//           x.second = p;
//        }
//    c) Else if (fre[p] !=0 && free[p] > y.first)
//       {
//           z = y
//           y.first = fre[p]
//           y.second = p
//       }
//    d) Else if (fre[p] !=0 && free[p] > z.first)
//       {
//           z.first = fre[p]
//           z.second = p
//       }

// // Modify frequency of Current element
// // as zero because We Traverse Initial
// // array arr[]. So it don't take same
// // values again
// 3) fre[p] = 0

// 3) Print x.second, y.second and z.second.