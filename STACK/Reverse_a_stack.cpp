#include <bits/stdc++.h>
using namespace std;

void ReverseStack(stack<int> &s)
{
    stack<int> s2;
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }

    cout << "Stack after reversal ";
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
}

int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    //    cout<<"Stack before reversal ";
    //     while (!s1.empty())
    //     {
    //         cout << s1.top() << " ";
    //         s1.pop();
    //     }
    ReverseStack(s1);
    return 0;
}