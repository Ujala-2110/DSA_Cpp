#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front = -1;
    int rear = -1;
    int arr[10];

    bool IsEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
        {
            return false;
        }
    }
    bool IsFull()
    {
        if (rear == 10)
            return true;
        else
        {
            return false;
        }
    }
    void enqueue(int data)
    {
        if (IsFull())
            return;
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void Dequeue()
    {
        if (IsEmpty())
            return;
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    void PrintQueue()
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(9);
    q.PrintQueue();
    q.Dequeue();
    q.Dequeue();
    q.PrintQueue();
    cout << q.IsEmpty() << "\n";
    return 0;
}