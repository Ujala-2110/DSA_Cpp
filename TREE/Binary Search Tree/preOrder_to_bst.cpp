
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

// A recursive function to construct Full from pre[].
// preIndex is used to keep track of index in pre[]
Node *constructTreeUtil(int pre[], int *preIndex, int low, int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;

    // The first node in preorder traversal is root. So take
    // the node at preIndex from pre[] and make it root, and
    // increment preIndex
    Node *root = new Node(pre[*preIndex]);
    *preIndex = *preIndex + 1;

    // If the current subarray has only one element, no need
    // to recur
    if (low == high)
        return root;

    // Search for the first element greater than root
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;

    // Use the index of element found in preorder to divide
    // preorder array in two parts. Left subtree and right
    // subtree
    root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);

    return root;
}
// O(n^2)

Node *constructTree(int *pre, int size)
{
    int preindex = 0;
    return constructTreeUtil(pre, &preindex, 0, size - 1, size);
}

// Node* build(vector<int>&preorder, int &i , int bound)
// {
//     if(i == preorder.size() || preorder[i] > bound) return NULL;
    
//     Node *root = new Node(preorder[i++]);
//     root->left = build(preorder,i,root->data);
//     root->right = build(preorder,i,bound);
    
//     return root;
// }

// Node* bstFromPreorder(vector<int>& preorder) {
    
//     int i = 0;
//     return build(preorder,i,INT_MAX);
// }

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
