#include <bits/stdc++.h>
using namespace std;

int mi = 99999;
void push(stack<int> &s, int a)
{
    // Your code goes here
    if (s.empty())
    {
        mi = a;
        s.push(a);
    }
    else
    {
        int x = a;
        if (a < mi)
        {
            x = 2 * a - mi;
            mi = a;
        }
        s.push(x);
    }
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    if (s.size() == n)
        return true;
    else
    {
        return false;
    }
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    if (s.empty())
        return true;
    else
    {
        return false;
    }
}

void pop(stack<int> &s)
{
    // Your code goes here
    int v = s.top();
    if (v >= mi)
        s.pop();
    else
    {
        int y = 2 * mi - v;
        s.pop();
        mi = y;
    }
}

int getMin(stack<int> &s)
{
    // Your code goes here
    return mi;
}

int main()
{
    stack<int> s;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << getMin(s)<<"\n";
    push(s, 5);
    // pop(s);
    push(s, 8);
    push(s, 2);
    pop(s);
    cout << getMin(s)<<"\n";
}