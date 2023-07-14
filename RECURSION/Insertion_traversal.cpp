#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Node *newNode(int data)
// {
//     Node *new_node = new Node;
//     new_node->data = data;
//     new_node->next = NULL;
//     return new_node;
// }

Node *insertEnd(Node *head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
        return new_node;

    else
        head->next = insertEnd(head->next, data);
    return head;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";

    traverse(head->next);
}

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head);
}
