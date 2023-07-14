#include <bits/stdc++.h>
using namespace std;

void Reverse_queue(queue<int> &q)
{
    if (q.empty())
        return;
    int ele = q.front();
    q.pop();
    Reverse_queue(q);
    q.push(ele);
}
// void Reverse_queue(queue<int> &q)
// {
//     stack<int> s;
//     while (!q.empty())
//     {
//         s.push(q.front());
//         q.pop();
//     }
//     while (!s.empty())
//     {
//         q.push(s.top());
//         s.pop();
//     }
// }

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    Reverse_queue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}