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

void InsertAtBegin(Node **head, int val)
{
    Node *n = new Node(val);

    if (*head == NULL)
    {
        n->next = n;
        *head = n;
        return;
    }

    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = n;
    n->next = *head;
    *head = n;
}

void InsertAtEnd(Node **head, int val)
{
    Node *n = new Node(val);

    if (*head == NULL)
    {
        InsertAtBegin(head, val);
        return;
    }
    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = n;
    n->next = *head;
}

void Display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}

void DeleteAtHead(Node **head)
{
    Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    Node *todelete = *head;
    temp->next = (*head)->next;
    *head = (*head)->next;

    delete todelete;
}

void Deletion(Node **head, int pos)
{
    if (pos == 1)
    {
        DeleteAtHead(head);
        return;
    }
    Node *temp = *head;
    int ct = 1;
    while (temp->next != *head && ct != pos - 1)
    {
        temp = temp->next;
        ct++;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    Node *head = NULL;
    InsertAtEnd(&head, 1);
    InsertAtEnd(&head, 2);
    InsertAtEnd(&head, 3);
    InsertAtEnd(&head, 4);
    Display(head);
    InsertAtBegin(&head, 5);
    Display(head);
    Deletion(&head,5);
    DeleteAtHead(&head);
    Display(head);
    return 0;
}
