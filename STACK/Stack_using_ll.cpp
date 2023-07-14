#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

bool isEmpty(StackNode *head)
{
    if (head == NULL)
        return true;
    else
        return false;
}

void push(StackNode **head, int data)
{
    StackNode *newNode = new StackNode();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    cout << data << " pushed to stack\n";
}

int pop(StackNode **head)
{
    if (isEmpty(*head))
        return -1;
    StackNode *temp = *head;
    *head = (*head)->next;
    int x= temp->data;
    free(temp);

    return x;
}

int peek(StackNode *head)
{
    if (isEmpty(head))
        return -1;
    return head->data;
}

int main()
{
    StackNode *root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";

    cout << "Top element is " << peek(root) << endl;

    cout << "Elements present in stack : ";
    //print all elements in stack :
    while (!isEmpty(root))
    {
        // print top element in stack
        cout << peek(root) << " ";
        // remove top element in stack
        pop(&root);
    }

    return 0;
}