//Algorithm
//  Write a program to store the values in a circular queue from another Circular queue.

/* make another queue of same size
and assign front value of first queue in rear of second queue and 
dequeue element from the 1st queue and increment rear of second queue
by 1 and assign front value of first queue in rear of second queue 
and at last assign the last element of queue 1 in queue 2;
*/

#include <bits/stdc++.h>
using namespace std;
const int n = 100;

int q1[n];
int q2[n];
int front = -1, front1 = 0;
int rear = -1, rear1 = 0;

int ct = 0;
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
            cout << q1[i] << " ";
    else
    {
        for (int i = front; i < n; i++)
            cout << q1[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << q1[i] << " ";
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
        q1[rear] = data;
    }
    else
    {
        rear = (rear + 1) % n;
        q1[rear] = data;
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

void printsecond()
{
    while (front !=rear)
    {
        q2[rear1] = q1[front];
        dequeue();
        rear1 = (rear1 + 1) % n;
    }
    q2[rear1] = q1[front];
    if (rear1 >= front1)
    {
        for (int i = front1; i <= rear1; i++)
            cout << q2[i] << " ";
    }
    else
    {
        for (int i = front1; i < n; i++)
            cout << q2[i] << " ";
        for (int i = 0; i <= rear1; i++)
            cout << q2[i] << " ";
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
            printsecond();
            cout << endl;
            break;
        }
        }
    }
    return 0;
}