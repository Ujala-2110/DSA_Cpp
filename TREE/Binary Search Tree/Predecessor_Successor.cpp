#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node *inpre(Node *root)
{
    Node *p = root->left;
    while (p->right)
        p = p->right;
    return p;
}

Node *insuc(Node *root)
{
    Node *p = root->right;
    while (p->left)
        p = p->left;
    return p;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left)
            pre = inpre(root);
        if (root->right)
            suc = insuc(root);
        return;
    }
    if (key > root->data)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->data)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

int main()
{
    int key = 65; //Key to be searched in BST

    /* Let us create following BST
		  50  
		 /	 \
		30	 70
		/ \ / \
	  20 40 60 80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    Node *pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor is " << pre->data << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->data;
    else
        cout << "No Successor";
    return 0;
}

// Method 2 (Search from root)
// Parent pointer is NOT needed in this algorithm. The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

// Input: node, root // node is the node whose Inorder successor is needed.

// Output: succ // succ is Inorder successor of node.

// If right subtree of node is not NULL, then succ lies in right subtree. Do the following.
// Go to right subtree and return the node with minimum key value in the right subtree.
// If right subtree of node is NULL, then start from the root and use search-like technique. Do the following.
// Travel down the tree, if a node's data is greater than root's data then go right side, otherwise, go to left side.
