#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void linkedlistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;

    else
        return 0;
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return 1;

    else
        return 0;
}

struct node *Push(struct node *top, int x)
{
    if (isFull(top))
        printf("Stack overflow");

    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node *tp)
{
    if (isEmpty(tp))
        printf("Stack underflow");

    else
    {
        struct node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
        return ptr->data;

    else
        return -1;
}
int main()
{
    top = Push(top, 28);
    top = Push(top, 18);
    top = Push(top, 15);
    top = Push(top, 7);

    linkedlistTraversal(top);
    for (int i = 1; i <=4; i++)
    {
        printf("value at position %d is : %d\n", i, peek(i));
    }
    return 0;
}
