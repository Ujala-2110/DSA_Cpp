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

/*
 int height(TreeNode *root)
{
    if(root == NULL) return 0;
    
    int lh = height(root->left);
    if(lh == -1) return -1;
    int rh = height(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh-rh) > 1) return -1;
    return 1+max(lh,rh);
}

bool isBalanced(TreeNode* root) {
    
    if(height(root) != -1) return true;
    return false;
}
*/

int height(Node *root)
{
    if (root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

// bool isBalanced(Node *root)
// {
//  if(root == NULL) return true;

//     int lh = height(root->left);
//     int rh = height(root->right);

//     if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
//     return false;
// }

//O(n^2)

//optimized version
int solve(Node *root, int *f)
{
    if (!root) return 0;
    int l = solve(root->left, f);
    int r = solve(root->right, f);
    if (abs(l - r) > 1) *f = 0;
    return max(l, r) + 1;
}

bool isBalanced(Node *root)
{
    int f = 1;
    solve(root, &f);
    return f;
}

//O(n)

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}