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
    cout << arr[top] << " Value popped " << "\n";
    top--;
}
void printStack()
{
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int ct =5;
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
            push(data);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            printStack();
            break;
        }
        }
    }
    return 0;
}