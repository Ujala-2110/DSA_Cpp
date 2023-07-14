#include <bits/stdc++.h>
using namespace std;

//You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input 
//parameter and returns the nth root of m. If the root is not integer then returns -1.
 
double multiply(int mid, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
    }

    return ans;
}

int NthRoot(int n, int m)
{
    // Code here.
    int l = 1;
    int h = m;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        double mul = multiply(mid, n);

        if (mul == m)
            return mid;
        else if (mul < m)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1;
}
//Expected Time Complexity: O(n* log(m))
//Expected Space Complexity: O(1)


//M-> 2

//Find the N'th root of M correct upto 6 decimal palces
// double multiply(double mid , int n)
// {
//     double ans = 1.0;
//     for(int i=1;i<=n;i++)
//     {
//         ans = ans * mid;
//     }
//     return ans;
// }

// double findNthRootOfM(int n, int m) {
// 	// Write your code here.
//     double low = 1;
//     double high = m;
//     double eps = 1e-8; 

//     while((high - low) > eps) {
//         double mid = (low + high) / 2.0; 
//         double mul = multiply(mid, n);
//         if(mul == m) return mid;
//         else if(mul < m) {
//             low = mid; 
//         }
//         else {
//             high = mid; 
//         }
//     }
//     return low;
// }
int main()
{
    int n = 2, m = 36;
    cout << NthRoot(n, m);
    // cout << findNthRootOfM(n, m);
    return 0;
}