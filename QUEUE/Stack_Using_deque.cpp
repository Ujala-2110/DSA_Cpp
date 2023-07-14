#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    deque<int> dq;
    int ct = 0;
    void push(int data)
    {
        dq.push_front(data);
        ct++;
    }

    void pop()
    {
        dq.pop_front();
        ct--;
    }
    int top()
    {
        if (dq.empty())
            return -1;

        int x = dq.front();
        return x;
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