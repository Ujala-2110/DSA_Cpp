// Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
// For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

// Note: It is recommended do this in-place without altering the node's values.

// C++ program to rearrange a linked list in-place
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverselist(Node *head)
{
    Node *prev = NULL, *curr = head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}

// Function to rearrange a linked list
Node* rearrange(Node *head)
{
    //Tortoise method to find middle of linked list
    Node *slow = head, *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    head2 = reverselist(head2);

    head = new Node(0);

    Node *curr = head;
    while (head1 || head2)
    {

        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    head = head->next;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printlist(head);  // Print original list
    head = rearrange(head); // Modify the list
    printlist(head);  // Print modified list
    return 0;
}

