#include <bits/stdc++.h>
using namespace std;

//boardgame counting path using dice that's why i have used loop.
int Countpath(int s, int e)
{
    if (s == e)
        return 1;

    if (s > e)
        return 0;

    int count = 0;
    for(int i=1;i<=6;i++)
    {
        count += Countpath(s+i,e);
    }

    return count;
}

int main()
{
    cout << Countpath(0, 3);
    return 0; 
}