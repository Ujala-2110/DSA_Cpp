// A Stack based C++ program to find next
// greater element for all array elements
// in same order as input.
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNGE(arr, n);
    return 0;
}
