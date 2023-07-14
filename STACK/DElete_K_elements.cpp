#include <bits/stdc++.h>
using namespace std;

void deleteElements(int arr[], int n, int k)
{
    stack<int> s;
    s.push(arr[0]);
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        // condition for deleting an element
        while (!s.empty() && s.top() < arr[i] && count < k)
        {
            s.pop();
            count++;
        }

        s.push(arr[i]);
    }

    //Putting elements of stack in a vector from end to begin.
    int m = s.size();
    vector<int> v(m); // Size of vector is m
    while (!s.empty())
    {
        // push element from stack to vector v
        v[--m] = s.top();
        s.pop();
    }

    // printing result
    for (auto x : v)
        cout << x << " ";

    cout << endl;
}

int main()
{
    int arr[] = { 3, 100, 1 };
    int k = 1;
    int n = sizeof(arr) / sizeof(int);
    deleteElements(arr, n, k);
    return 0;
}
