#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *Insert(Node *root, int key)
{
    // Your code here
    if (root == NULL) return new Node(key);

    if (key < root->data)
        root->left = Insert(root->left, key);

    if (key > root->data)
        root->right = Insert(root->right, key);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = Insert(root, 5);
    Insert(root, 3);
    Insert(root, 2);
    Insert(root, 4);
    Insert(root, 7);
    Insert(root, 6);
    Insert(root, 8);

    Inorder(root);
    return 0;
}