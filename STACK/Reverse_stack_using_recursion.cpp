#include <bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }

    int topele = s.top();
    s.pop();
    InsertAtBottom(s, ele);

    s.push(topele);
}

void ReverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int ele = s.top();
    s.pop();
    ReverseStack(s);
    InsertAtBottom(s, ele);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // cout << "Stack before reversal\n ";
    ReverseStack(s);
    cout<<"Stack after reversal\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}