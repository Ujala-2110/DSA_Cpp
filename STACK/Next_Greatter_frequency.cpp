#include <bits/stdc++.h>
using namespace std;

void NGF(int arr[], int n)
{
    stack<int> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int nge[n];
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && mp[arr[i]] > mp[arr[s.top()]])
        {
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout <<(nge[i] == -1 ? -1 : arr[nge[i]])<<" ";
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    NGF(arr, n);
    return 0;
}