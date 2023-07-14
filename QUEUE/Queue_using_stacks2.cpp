// CPP program to implement Queue using
// two stacks with costly deQueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1;

    void enQueue(int x)
    {
        s1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s1.empty())
            return -1;

        // pop an item from the stack
        int ele = s1.top();
        s1.pop();

        // if stack becomes empty, return
        // the popped item
        if (s1.empty())
            return ele;

        // push popped item back to the stack
        int item = deQueue();

        // push popped item back to the stack
        s1.push(ele);

        return item;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}
