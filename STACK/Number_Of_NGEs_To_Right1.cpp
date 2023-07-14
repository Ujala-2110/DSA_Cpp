#include <bits/stdc++.h>
using namespace std;
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define vl vector<int>
#define pb push_back

void NGER(int arr[], int n)
{
    stack<int> s;
    int nge[n];
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[0] < arr[s.top()])
        {
            ct++;
            s.pop();
        }
        s.push(i);
    }

    cout << ct;
}
int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(arr) / sizeof(int);

    NGER(arr, n);
    return 0;
}