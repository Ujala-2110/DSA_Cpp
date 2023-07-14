#include <bits/stdc++.h>
using namespace std;

void InsertAt_correct_position(stack<int> &s, int ele)
{
    if (s.size() == 0 || s.top() < ele)
    {
        s.push(ele);
        return;
    }

    int topele = s.top();
    s.pop();
    InsertAt_correct_position(s, ele);

    s.push(topele);
}

void sortArrayUsingStacks(int arr[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        InsertAt_correct_position(s, ele);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int arr[] = {10, 5, 15, 45, 25, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArrayUsingStacks(arr, n);

    return 0;
}
