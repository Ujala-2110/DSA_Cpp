#include <iostream>
using namespace std;
class stack
{
    int stack[100];
    int top = -1;

public:
    void push(int data)
    {
        if (top > 99)
            cout << "Stack Overflow" << endl;

        else
        {
            top += 1;
            stack[top] = data;
        }
    }
    void pop()
    {
        if (top > -1)
            top--;
    }
    void display()
    {
        if (top <= 99 && top > -1)
        {
            for (int i = top; i >= 0; i--)
                cout << stack[i] << " ";
        }
    }
};

int main()
{
    int option, data;
    stack Stack;
    while (1)
    {
        cout << "\n1.Push data\n2.Pop data\n3.Display data\n4.Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter Data ";
            cin >> data;
            Stack.push(data);
            break;
        case 2:
            Stack.pop();
            break;
        case 3:
            Stack.display();
            break;
        case 4:
            cout << "successfully exited";
            
        }
    }
    return 0;
}