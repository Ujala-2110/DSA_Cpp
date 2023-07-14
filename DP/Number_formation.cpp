// Given three integers X, Y and Z, the task is to find the sum of all the numbers formed having 4 at most X times, 5 at most Y times, and 6 at most Z times, under mod 10^9+7.
// Examples:

// Input: X = 1, Y = 1, Z = 1
// Output: 3675
// Explanation:
// 4 + 5 + 6 + 45 + 54 + 56
// + 65 + 46 + 64 + 456 + 465
// + 546 + 564 + 645 + 654 = 3675

// Input: X = 4, Y = 5, Z = 6
// Output: 129422134

// Approach:

// As this problem has the property of sub-problems overlapping and optimal sub-structure, hence dynamic programming can be used to solve it.
// The numbers having exact i 4s, j 5s, and k 6s for all i < x, j < y, j < z are required to get the required sum.
// Therefore the DP array exactnum[i][j][k] will store the exact count of numbers having exact i 4s, j 5s, and k 6s.
// If exactnum[i – 1][j][k], exactnum[i][j – 1][k] and exactnum[i][j][k – 1] are already known, then it can be observed that the sum of these is the required answer, except in the case when exactnum[i – 1][j][k], exactnum[i][j – 1][k] or exactnum[i][j][k – 1] doesn’t exist. In that case, just skip it.
// exactsum[i][j][k] stores the sum of the exact number having i 4’s, j 5’s, and k 6’s in the same way as

// exactsum[i][j][k] = 10 * (exactsum[i - 1][j][k]
//                         + exactsum[i][j - 1][k]
//                         + exactsum[i][j][k - 1])
//                   + 4 * exactnum[i - 1][j][k]
//                   + 5 * exactnum[i][j - 1][k]
//                   + 6 * exactnum[i][j][k - 1]

// C++ program to find sum of all numbers
// formed having 4 atmost X times, 5 atmost
// Y times and 6 atmost Z times
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int mod = 1e9 + 7;

// exactsum[i][j][k] stores the sum of
// all the numbers having exact
// i 4's, j 5's and k 6's
int exactsum[N][N][N];

// exactnum[i][j][k] stores numbers
// of numbers having exact
// i 4's, j 5's and k 6's
int exactnum[N][N][N];

// Utility function to calculate the
// sum for x 4's, y 5's and z 6's
int getSum(int x, int y, int z)
{
    int ans = 0;
    exactnum[0][0][0] = 1;
    for (int i = 0; i <= x; ++i)
    {
        for (int j = 0; j <= y; ++j)
        {
            for (int k = 0; k <= z; ++k)
            {
                if (i > 0)
                {
                    exactsum[i][j][k] += (exactsum[i - 1][j][k] * 10 + 4 * exactnum[i - 1][j][k]) % mod;
                    exactnum[i][j][k] += exactnum[i - 1][j][k] % mod;
                }
                if (j > 0)
                {
                    exactsum[i][j][k] += (exactsum[i][j - 1][k] * 10 + 5 * exactnum[i][j - 1][k]) % mod;
                    exactnum[i][j][k] += exactnum[i][j - 1][k] % mod;
                }
                if (k > 0)
                {
                    exactsum[i][j][k] += (exactsum[i][j][k - 1] * 10 + 6 * exactnum[i][j][k - 1]) % mod;
                    exactnum[i][j][k] += exactnum[i][j][k - 1] % mod;
                }

                ans += exactsum[i][j][k] % mod;
                ans %= mod;
            }
        }
    }
    return ans;
}

int main()
{
    int x = 1, y = 1, z = 1;

    cout << (getSum(x, y, z) % mod);

    return 0;
}

// Time Complexity: O(x*y*z)
// Auxiliary Space: O(N3)