#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1, q2;
    int ct = 0;
    void push(int data)
    {
        ct++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop()
    {
        if (q1.empty())
        return;
        q1.pop();
        ct--;
    }
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return ct;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() << endl;
    return 0;
}