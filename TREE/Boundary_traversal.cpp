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
// A simple function to print leaf nodes of a binary tree
void printLeaves(Node *root)
{
    if (root == NULL) return;

    printLeaves(root->left);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        printf("%d ", root->data);

    printLeaves(root->right);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node *root)
{
    if (root == NULL) return;

    if (root->left)
    {

        // to ensure top down order, print the node
        // before calling itself for left subtree
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node *root)
{
    if (root == NULL) return;

    if (root->right)
    {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary tree
void printBoundary(Node *root)
{
    if (root == NULL) return;

    printf("%d ", root->data);

    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);

    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);

    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}

/*
bool isLeaf(TreeNode<int>* root)
{
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

void addLeft(TreeNode<int>* root, vector<int>&ans)
{
    TreeNode<int>* cur = root->left;
    while(cur)
    {
        if(!isLeaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRight(TreeNode<int>* root, vector<int>&ans)
{
    TreeNode<int>* cur = root->right;
    vector<int>tmp;
    while(cur)
    {
        if(!isLeaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    
    for(int i=(tmp.size()-1);i>=0;i--) ans.push_back(tmp[i]);
}

void addLeaves(TreeNode<int>* root, vector<int>&ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)addLeaves(root->left,ans);
    if(root->right)addLeaves(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeft(root,ans);
    addLeaves(root,ans);
    addRight(root,ans);
    return ans;
}
*/

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    printBoundary(root);

    return 0;
}