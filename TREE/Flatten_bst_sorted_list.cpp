#include <bits/stdc++.h> 
using namespace std;

// Following is the Binary Tree node structure

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


void inorder(TreeNode<int>* root, vector<TreeNode<int>*>&ans)
{
    if(root == NULL) return;

    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*>ans;
    inorder(root,ans);

    TreeNode<int>* head = ans[0];
    TreeNode<int>* curr = head;


    for(int i=1;i<ans.size();i++)
    {
        TreeNode<int> *temp = ans[i];
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
        
    }
    curr->left = NULL;
    curr->right = NULL;
    return head;
}


//Method -> 2

void inorder(TreeNode<int>* curr, TreeNode<int>*& prev)
{
    if (curr == NULL) return;

    inorder(curr->left, prev);
    
    prev->left = NULL;
    prev->right = curr;
    prev = curr;

    inorder(curr->right, prev);
} 


TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* dummy = new TreeNode<int>(-1);
    TreeNode<int>* prev = dummy;
    
    inorder(root, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    return dummy->right;
}