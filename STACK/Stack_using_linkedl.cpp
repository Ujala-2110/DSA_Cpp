#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int isEmpty(Node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    Node *n = new Node();
    if (n == NULL)
        return 1;
    else
        return 0;
}
void push(Node **top, int value)
{
    Node *n = new Node();
    n->data = value;
    n->next = *top;
    *top = n;
}

int pop(Node *top)
{
    Node *temp;
    temp = top;
    top = top->next;
    int x = temp->data;
    free(temp);
}

int isTop(Node *top)
{
    return top->data;
}

void printStack(Node *top)
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main()
{
    Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    pop(top);
    push(&top, 30);
    cout << isTop(top) << "\n";
    printStack(top);
    pop(top);
    pop(top);
    cout << isEmpty(top) << "\n";
    return 0;
}