#include <bits/stdc++.h>
using namespace std;

bool check(int *arr, int n)
{
    stack<int> st;
    int expected = 1;
    int fnt;

    for (int i = 0; i < n; i++)
    {
        fnt = arr[i];
        if (fnt == expected)
            expected++;

        else
        {
            if (st.empty())
                st.push(fnt);

            else if (!st.empty() && st.top() < fnt)
                return false;
            else
            {
                st.push(fnt);
            }
        }
    }
    while (!st.empty() && st.top() == expected)
    {
        st.pop();
        expected++;
    }
    if (expected - 1 == n && st.empty())
        return true;

    return false;
}
int main()
{
    int A[] = {4, 1, 2, 3};
    int n = sizeof(A) / sizeof(A[0]);
    check(A, n) ? cout << "YES" : cout << "NO";
    return 0;
}
