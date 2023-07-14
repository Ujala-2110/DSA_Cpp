#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, Node *new_node)
{
    new_node->prev = NULL;
    new_node->next = *head_ref;

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

Node *getNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        cout << temp->data<<" ";
}

Node *Reverse(Node *head)
{
    if(head == NULL)
    return NULL;

    // Otherwise, swap the next and prev
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    // If the prev is now NULL, the list
    // has been fully reversed
    if (head->prev == NULL)
        return head;
    
    // Otherwise, keep going
    return Reverse(head->prev);
}

int main()
{
    // Start with the empty list
    Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2 */
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list
    head = Reverse(head);
    cout << "\nReversed list: ";
    printList(head);
    return 0;
}