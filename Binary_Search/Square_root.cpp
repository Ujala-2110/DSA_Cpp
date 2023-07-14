#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    int l = 1, h = x;
    int rt = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (mid == x / mid) return mid;

        else if (mid < x / mid)
        {
            rt = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    return rt;
}

int main()
{
    int x = 16;
    cout<<mySqrt(x);
    return 0;
}