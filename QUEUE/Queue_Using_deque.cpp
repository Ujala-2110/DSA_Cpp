#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    deque<int>dq;

    void enQueue(int x)
    {
      dq.push_front(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
      if(dq.empty())
        return -1;
      int x = dq.back();
      dq.pop_back();
      return x;
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
