#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Deque
{
    Node *front;
    Node *rear;
    int size;

public:
    Deque()
    {
        front = rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    void insertFront(int val)
    {
        Node *n = new Node(val);

        if (n == NULL)
            return;
        if (front == NULL)
        {
            front = rear = n;
        }

        n->next = front;
        front->prev = n;
        front = n;     

        size++;
    }
    void insertRear(int val)
    { 
        Node *n = new Node(val);

        if (n == NULL)
            return;
        if (rear == NULL)
        {
            front = rear = n;
        }
        n->prev = rear;
        rear->next = n;
        rear = n;

        size++;
    }
    void deleteFront()
    {
        if (isEmpty())
            return;
        Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        delete temp;

        size--;
    }
    void deleteRear()
    {
        if (isEmpty())
            return;
        Node *temp = rear;
        rear = rear->prev;
        if (front == NULL)
            rear = NULL;
        else
            rear->next = NULL;
        delete temp;

        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return front->data;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;

        return rear->data;
    }
    int Size()
    {
        return size;
    }
    void erase()
    {
        rear = NULL;
        while (front != NULL)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        size = 0;
    }
};

int main()
{
    Deque dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertRear(5);

    cout << "Insert element '10' at rear end\n";
    dq.insertRear(10);

    cout << "Rear end element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After deleting rear element new rear" << " is: " << dq.getRear() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);

    cout << "Front end element: " << dq.getFront() << endl;

    cout << "Number of elements in Deque: " << dq.Size() << endl;

    dq.deleteFront();
    cout << "After deleting front element new " << "front is: " << dq.getFront() << endl;

    return 0;
}