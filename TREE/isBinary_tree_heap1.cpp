#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

bool isHeap(Node *root)
{
    queue<Node *> q;
    q.push(root);
    bool nullish = false;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (nullish || temp->left->data >= temp->data)
            {
                return false;
            }
            q.push(temp->left);
        }
        else
        {
            nullish = true;
        }
        if (temp->right)
        {
            if (nullish || temp->right->data >= temp->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            nullish = true;
        }
    }
    return true;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}