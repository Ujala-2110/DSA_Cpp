#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Recursive Function to delete the entire linked list */
void deleteList(struct Node *head)
{
    if (head == NULL)
        return;
    deleteList(head->next);
    free(head);
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct Node *head = NULL;

    /* Use push() to construct below list
	1->12->1->4->1 */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    printf("\n Deleting linked list");
    deleteList(head);

    // Since head now points to illgal address, we should set head = NULL:
    head = NULL;
    printf("\nLinked list deleted");
    return 0;
}
