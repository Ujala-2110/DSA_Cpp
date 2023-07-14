#include <bits/stdc++.h>
using namespace std;
#define size 10

class Queue
{
public:
    int front = -1;
    int rear = -1;
    int arr[size];

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
        if (front == (rear + 1) % size)
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
        else if (IsEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }
    int Dequeue()
    {
        if (IsEmpty())
            return -1;
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            int x = arr[front];
            front = (front + 1) % size;
            return x;
        }
        return -1;
    }
    void displayqueue()
    {
        if (front == -1)
        {
            "Queue is empty";
            return;
        }
        else if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout<<"\n";
    }
};

int main()
{
    Queue q;

    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    // Display elements present in Circular Queue
    q.displayqueue();
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.Dequeue());
    printf("\nDeleted value = %d", q.Dequeue());
    cout<<"\n";

    q.displayqueue();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.displayqueue();

    q.enqueue(20);
    return 0;
}