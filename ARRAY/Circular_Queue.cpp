//Algorithm

// Front: Get the front item from queue.
// Rear: Get the last item from queue.
// enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position.
// Check whether queue is Full – Check (front == (rear+1)%MaxSize).
// If it is full then display Queue is full. If queue is not full then, check if (isEmpty()) if it is true then setfront=0 and rear=0 and insert element.
// deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position.
// Check whether queue is Empty means check (front==-1).
// If it is empty then display Queue is empty. If queue is not empty then step 3
// Check if (front==rear) if it is true then set front=rear= -1.else  front = (front + 1) % n.

#include <bits/stdc++.h>
using namespace std;
const int n = 100;

int arr[n];
int front = -1;
int rear = -1;

bool isFull()
{
    if (front == (rear + 1) % n)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

void printQueue()
{
    if (front == -1)
    {
        "Queue is empty";
        return;
    }

    if (rear >= front)
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    else
    {
        for (int i = front; i < n; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
}

void enqueue(int data)
{
    if (isFull())
        return;
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear = (rear + 1) % n;
        arr[rear] = data;
    }
}

void dequeue()
{
    if (isEmpty())
        return;
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

int main()
{
    int ct = 10;
    while (ct--)
    {
        cout << "Enter your choice\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter a data to be pushed ";
            cin >> data;
            enqueue(data);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            printQueue();
            break;
        }
        }
    }
    return 0;
}