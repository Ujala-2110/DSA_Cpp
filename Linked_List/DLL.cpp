#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtbegin(Node **head, int val)
{
    Node *n = new Node(val);
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    else
    {
        (*head)->prev = n;
        n->next = *head;
        *head = n;
    }
}
void InsertAtEnd(Node **head, int val)
{
    Node *n = new Node(val);
    if (*head == NULL)
    {
        InsertAtbegin(head, val);
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void InsertAtMiddle(Node **head, int val, int pos)
{
    Node *n = new Node(val);
    if (*head == NULL)
    {
        InsertAtbegin(head, val);
        return;
    }
    Node *temp = *head;
    Node *temp2 = *head;
    int ct = 1;
    while (temp != NULL && ct != pos - 1)
    {
        temp = temp->next;
        ct++;
    }

    temp2 = temp->next;
    temp->next = n;
    temp2->prev = n;
    n->prev = temp;
    n->next = temp2;
}
void DeleteAthead(Node **head)
{
    Node *todelete = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    delete todelete;
}

void Deletion(Node **head, int pos)
{
    if (*head == NULL)
        return;

    if (pos == 1)
    {
        DeleteAthead(head);
        return;
    }

    Node *temp = *head;
    int ct = 1;
    while (temp != NULL && ct != pos)
    {
        temp = temp->next;
        ct++;
    }
    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void Display(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
}

int main()
{
    Node *head = NULL;
    InsertAtbegin(&head, 1);
    InsertAtbegin(&head, 2);
    InsertAtbegin(&head, 3);
    InsertAtbegin(&head, 4);
    InsertAtEnd(&head, 5);
    InsertAtMiddle(&head, 8, 2);
    InsertAtMiddle(&head, 9, 3);
    InsertAtEnd(&head, 6);
    Display(head);
    cout << "\n";
    Deletion(&head, 5);
    Display(head);
    return 0;
}