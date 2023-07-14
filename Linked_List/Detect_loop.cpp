#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int flag;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void push(Node **head, int x)
{
    Node *new_node = new Node(x);

    new_node->next = (*head);
    (*head) = new_node;
}

// bool detectLoop(Node *head)
// {
//     Node *fr = head;
//     Node *sec = head;

//     while (fr != NULL && sec != NULL && sec->next != NULL)
//     {
//         fr = fr->next;
//         sec = sec->next->next;
//         if (fr == sec)
//             return true;
//     }
//     return false;
// }
bool detectLoop(Node *h)
{
    while (h!= NULL)
    {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;

        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;

        h = h->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}