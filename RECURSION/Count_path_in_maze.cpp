#include <bits/stdc++.h>
using namespace std;

//nxn maze
int Countpath(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;

    if (i >= n || j >= n)
        return 0;

    return Countpath(n, i + 1, j) + Countpath(n, i, j + 1);
}

int main()
{
    cout << Countpath(3, 0, 0);
    return 0;
} 