#include <iostream>
using namespace std;
#define n 100

class stack
{
    int top;

public:
    int arr[n];
    stack() { top = -1; }

    void push(int data)
    {
        if (top == n - 1)
            return;
        top++;
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
            return -1;
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void printStack()
    {
        for (int i = 0; i <= top; i++)
            cout << arr[top];
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "value popped is" << s.pop() << endl;
    cout << s.Top() << endl;
    cout << "value popped is" << s.pop() << endl;
    cout << "value popped is" << s.pop() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}