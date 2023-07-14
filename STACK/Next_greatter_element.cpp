#include <bits/stdc++.h>
using namespace std;
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define v vector<int>
#define pb push_back

void NGE(int arr[], int n)
{
    stack<int> s;
    int nge[n];
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
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
        cout << arr[i] << " " << (nge[i] == -1 ? -1 : arr[nge[i]]) << "\n";
}

int main()
{
    int arr[] = {4, 5, 2, 18, 25};
    int n = sizeof(arr) / sizeof(int);

    NGE(arr, n);
    return 0;
}