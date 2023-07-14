// Given the root of a binary tree, return all duplicate subtrees.
// For each kind of duplicate subtrees, you only need to return the root node of any one of them.
// Two trees are duplicate if they have the same structure with the same node values.

#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//Preorder and postorder dono kaam karega (not inorder)

string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
    if (!node) return "#";
    
    string left = serializeSubtrees(node->left, subtrees, duplicates);
    string right = serializeSubtrees(node->right, subtrees, duplicates);
    
    string s = left + "," + right + "," + to_string(node->val); 
    
    subtrees[s]++;
    if (subtrees[s] == 2) duplicates.push_back(node); 
    
    return s;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> subtrees; 
    vector<TreeNode*> duplicates; 
    
    serializeSubtrees(root, subtrees, duplicates); 
    return duplicates;
}