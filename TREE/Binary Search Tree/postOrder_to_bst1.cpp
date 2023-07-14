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

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
Node *constructTreeUtil(int pre[], int *PostIndex, int key, int min, int max, int size)
{
    // Base case
    if (*PostIndex < 0)
        return NULL;

    Node *root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new Node(key);
        *PostIndex = *PostIndex - 1;

        if (*PostIndex >=0)
        {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->right = constructTreeUtil(pre, PostIndex, pre[*PostIndex], key, max, size);
        }
        if (*PostIndex >=0)
        {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->left = constructTreeUtil(pre, PostIndex, pre[*PostIndex], min, key, size);
        }
    }

    return root;
}
// O(n)

Node *constructTree(int *pre, int size)
{
    int Postindex = size-1;
    return constructTreeUtil(pre, &Postindex, pre[size-1], INT_MIN, INT_MAX, size);
}

int main()
{
    int pre[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
