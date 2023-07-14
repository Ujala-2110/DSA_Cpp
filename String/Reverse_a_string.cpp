#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    // reverse(str.begin(), str.end());  [----->Method 1]
    int n= str.size();
    // for(int i=0;i<n/2;i++)
    // {
    //  swap(str[i] ,str[n-1-i]);        [------>Method 2]
    // }

    for(int i=n-1;i>=0;i--)
     cout<<str[i];
    // cout<<str;
    return 0;
}

// Ujala = alajU