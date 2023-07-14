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

int height(Node *root)
{
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(Node *root)
{
    if (root == NULL) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));

    // O(n^2)
}

int main()
{
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5 
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Function Call
    cout << "Diameter of the given binary tree is " << diameter(root);

    return 0;
}