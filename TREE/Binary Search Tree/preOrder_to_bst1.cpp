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
Node *constructTreeUtil(int pre[], int *preIndex, int key, int min, int max, int size)
{
    // Base case
    if (*preIndex >= size)
        return NULL;

    Node *root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new Node(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size)
        {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }

    return root;
}
// O(n)

Node *constructTree(int *pre, int size)
{
    int preindex = 0;
    return constructTreeUtil(pre, &preindex, pre[0], INT_MIN, INT_MAX, size);
}

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
