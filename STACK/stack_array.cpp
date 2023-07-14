#include <iostream>
using namespace std;
const int n = 10;

int arr[n];
int top = -1;

void push(int data)
{
    if (top == n - 1)
        return;
    top++;
    arr[top] = data;
}

void pop()
{
    if (top == -1)
        return;
    cout << arr[top] << " Value popped "
         << "\n";
    top--;
}

int isTop()
{
    if (top < 0)
        return -1;
    else
        return arr[top];
}
void printStack()
{
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool isEmpty()
{
    if (top < 0)
        return true;
    else
        return false;
}
int main()
{
    push(10);
    push(20);
    pop();
    push(30);
    cout << isTop() << "\n";
    printStack();
    pop();
    pop();
    cout << isEmpty() << "\n";
    return 0;
}