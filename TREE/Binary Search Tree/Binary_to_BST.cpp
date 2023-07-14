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
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void preorder(Node *root, vector<int> &v)
{
    if (root == NULL) return;
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

Node *sortedToBst(vector<int> &v, int l, int h)
{
    if (l > h) return NULL;

    int mid = (l + h) / 2;
    Node *root = new Node(v[mid]);

    root->left = sortedToBst(v, l, mid - 1);
    root->right = sortedToBst(v, mid + 1, h);

    return root;
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> v;
    preorder(root, v);
    sort(v.begin(), v.end());

    int n = v.size();
    return sortedToBst(v, 0, n - 1);
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in the above figure
        10
        / \
       30 15
      /     \
      20     5 */
    root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    // convert Binary Tree to BST
    root = binaryTreeToBST(root);

    cout << "Following is Inorder Traversal of the converted BST:" << endl;
    printInorder(root);

    return 0;
}