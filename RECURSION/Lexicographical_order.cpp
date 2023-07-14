#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    for (int j = 0; j < 10; j++)
        dfs(i * 10 + j, n);
}

int main()
{
    int n = 15;
    for (int i = 1; i <= 9; i++)
        dfs(i, n);
    return 0;
}
