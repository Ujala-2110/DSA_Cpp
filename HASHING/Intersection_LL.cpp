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

void InsertAtTail(Node **head, int val)
{
    Node *n = new Node(val);
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    return;
}

void push(Node **head, int val)
{
    Node *n = new Node(val);
    if (*head == NULL)
    {
        *head = n;
        return;
    }

    n->next = *head;
    *head = n;
}

void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
}

Node *findIntersection(Node *head1, Node *head2)
{
    // code here
    map<int, int> m;
    Node *head = NULL;
    // return the head of intersection list
    for (Node *temp1 = head1; temp1 != NULL; temp1 = temp1->next)
    {
        m[temp1->data]++;
    }
    for (Node *temp2 = head2; temp2 != NULL; temp2 = temp2->next)
    {
        if (m[temp2->data] == 1)
            m[temp2->data]--;

        else
            m[temp2->data]++;
    }

    for (auto it : m)
        if (it.second == 0)
            InsertAtTail(&head, it.first);

    return head;
}
Node *findUnion(Node *head1, Node *head2)
{
    // code here
    set<int>s;
    Node *head = NULL;
    // return the head of intersection list
    for (Node *temp1 = head1; temp1 != NULL; temp1 = temp1->next)
    {
        s.insert(temp1->data);
    }
    for (Node *temp2 = head2; temp2 != NULL; temp2 = temp2->next)
    {
        s.insert(temp2->data);
    }

    for (auto it : s)
        InsertAtTail(&head, it);

    return head;
}

int main()
{
    /* Start with the empty list */
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    /* create a linked list 11->10->15->4->20 */
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);

    /* create a linked list 8->4->2->10 */
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 6);

    printf("First list is \n");
    printList(head1);

    printf("\nSecond list is \n");
    printList(head2);
    cout<<"Intersection\n";
    Node *head = findIntersection(head1, head2);
    printList(head);
    cout<<"Union \n";
    Node *headn = findUnion(head1, head2);
    printList(headn);
    return 0;
}