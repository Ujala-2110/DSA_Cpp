#include <bits/stdc++.h>
using namespace std;

void Insert_At_position(stack<int> &s, int ele)
{
    if (s.size() == 0 || s.top() > ele)
    {
        s.push(ele);
        return;
    }
    int topele = s.top();
    s.pop();
    Insert_At_position(s, ele);

    s.push(topele);
}

void Sort(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        Insert_At_position(s, ele);
    }

    queue<int> q1;
    while (!s.empty())
    {
        q1.push(s.top());
        s.pop();
    }

    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
}

int main()
{
    //Queue[] = { 5, 1, 2, 3, 4 }
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    Sort(q);
    return 0;
}
