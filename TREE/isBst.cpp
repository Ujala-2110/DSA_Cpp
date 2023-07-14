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

void func(Node *root, Node *&prev, int &f)
{
    if (!root) return;
    func(root->left, prev, f);
    if (prev != NULL && root->data <= prev->data)
    {
        f = 0;
        return;
    }
    prev = root;
    func(root->right, prev, f);
}

bool isBST(Node *root)
{
    // Your code here
    int f = 1;
    Node *prev = NULL;
    func(root, prev, f);
    return f;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}