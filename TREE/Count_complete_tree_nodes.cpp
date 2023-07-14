// 222. Count Complete Tree Nodes

// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
// Design an algorithm that runs in less than O(n) time complexity.

#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int  leftMove(TreeNode *root)
{
    TreeNode *curr = root;
    int cnt = 0;
    while(curr)
    {
        cnt++;
        curr = curr->left;
    }
    return cnt;
}

int rightMove(TreeNode *root)
{
    TreeNode *curr = root;
    int cnt = 0;
    while(curr)
    {
        cnt++;
        curr = curr->right;
    }
    return cnt;
}

int countNodes(TreeNode* root) {
    
    if(root == NULL) return 0;

    int l = leftMove(root);
    int r = rightMove(root);

    if(l == r) return (1 << l)-1;

    return 1+countNodes(root->left) + countNodes(root->right);
}