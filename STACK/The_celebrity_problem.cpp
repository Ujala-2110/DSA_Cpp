#include <bits/stdc++.h>
using namespace std;

int Celebrity(int in[], int out[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == n - 1 & out[i] == 0)
            return i;
    }
    return -1;
}

int main()
{
    int n = 4;
    int in[n] = {0};
    int out[n] = {0};
    int MATRIX[n][n] = { {0, 0, 1, 0},
                         {0, 0, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 1, 0} };

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (MATRIX[i][j] == 1)
        {
            in[j]++;
            out[i]++;
        }
    }

    cout << Celebrity(in, out, n);
    return 0;
}