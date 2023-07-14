#include <bits/stdc++.h>
using namespace std;

void Delete_Middle(stack<int> &s, int n, int ct = 0)
{
    if (s.empty() || ct == n)               //|------>Base case
        return;

    int p = s.top();                        //|
    s.pop();                                //| -----> Basic steps for recursion
    Delete_Middle(s, n, ct + 1);            //|(recursive function)
    if (ct != n / 2)
        s.push(p);
}

// void Delete_Middle(stack<int> &s)
// {
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (n % 2 != 0)
//         {
//             if (i == n / 2)
//                 s.pop();
//         }
//         else
//         {
//             if (i == (n / 2) - 1)
//                 s.pop();
//         }

//         cout << s.top() << " ";
//         s.pop();
//     }
// }

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    // Delete_Middle(s);
    int n = s.size();
    Delete_Middle(s, n);
    while (!s.empty())
    {
        int p = s.top();
        s.pop();
        cout << p << " ";
    }
    return 0;
}