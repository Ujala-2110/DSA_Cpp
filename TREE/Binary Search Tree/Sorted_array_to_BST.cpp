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

Node *sortedArrayToBST(int *arr, int l, int h)
{
    if (l > h)
    return NULL;

    int mid = (l + h) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, l, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, h);

    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    /* Convert List to BST */
    Node *root = sortedArrayToBST(arr, 0, n - 1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);

    return 0;
}