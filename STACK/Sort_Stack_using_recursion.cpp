#include <bits/stdc++.h>
using namespace std;

void InsertAt_correct_position(stack<int> &s, int ele)
{
    if (s.size() == 0 || s.top()<ele)   // For descending order (s.top()>ele)
    {
        s.push(ele);
        return;
    }

    int topele = s.top();
    s.pop();
    InsertAt_correct_position(s, ele);

    s.push(topele);
}

void SortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int ele = s.top();
    s.pop();
    SortStack(s);
    InsertAt_correct_position(s, ele);
}

int main()
{
    stack<int> s;
    s.push(30);
    s.push(15);
    s.push(18);
    s.push(14);
    s.push(-3);
    // cout << "Stack before reversal\n ";
    SortStack(s);
    cout<<"Stack after sorting\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}