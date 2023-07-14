#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1, q2;
    int ct = 0;
    void push(int data)
    {
        ct++;
        q1.push(data);
    }

    void pop()
    {
        if (q1.empty() && q2.empty())
            return;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        ct--;
        q1.pop();
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    int top()
    {
        if (q1.empty())
            return -1;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
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
    s.push(4);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size()
         << endl;
    return 0;
}