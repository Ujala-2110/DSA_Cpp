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

Node *deleteNode(Node *head, int k)
{
    if (k < 1)
        return head;

    if (head == NULL)
        return NULL;

    if (k == 1)
    {
        Node *res = head->next; 
        delete (head);
        return res;

        // head = head->next;
        // return head;
    }

    head->next = deleteNode(head->next, k - 1);
    return head;
}

void push(Node **head_ref, int val)
{
    Node *n = new Node(val);

    n->next = *head_ref;
    *head_ref = n;
}

void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        cout << temp->data<<" ";
}

int main()
{
    Node *head = NULL;

    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);

    int k = 3;
    head = deleteNode(head, k);

    printf("\nModified Linked List: ");
    printList(head);

    return 0;
}