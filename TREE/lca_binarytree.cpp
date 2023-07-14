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

Node *lca(Node *root, int n1, int n2)
{
    //Your code here

    if (root == NULL) return root;

    if (root->data == n1 || root->data == n2) return root;

    Node *lcaleft = lca(root->left, n1, n2);
    Node *lcaright = lca(root->right, n1, n2);

    if (lcaleft != NULL && lcaright != NULL) return root;

    if (lcaleft != NULL) return lcaleft;

    else return lcaright;
}

int findLCA(Node *root,int n1,int n2)
{
    root = lca(root,n1,n2);
    return root->data;
}

int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}