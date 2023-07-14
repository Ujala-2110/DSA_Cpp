#include <bits/stdc++.h>
using namespace std;
const int n = 4;

int Celebrity(int MATRIX[n][n], int c)
{
    for (int i = 0; i < n; i++)
    {
        if (i != c && (MATRIX[c][i]) == 1 || MATRIX[i][c] == 0)
            return -1;
    }
    return c;
}

int main()
{

    int MATRIX[n][n] = {{0, 0, 1},
                        {0, 0, 1},
                        {0, 0, 0},
                        {0, 0, 1}};

    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (MATRIX[c][i] == 1)
            c = i;
    }

    cout << Celebrity(MATRIX, c);
    return 0;
}