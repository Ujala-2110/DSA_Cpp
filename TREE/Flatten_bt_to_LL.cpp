#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


//Using Morris traversal
void flatten(TreeNode* root) {
    
    TreeNode *cur = root;
    TreeNode *prev = NULL;
    while(cur != NULL)
    {    
        if(cur->left != NULL)
        {
            prev = cur->left;
            while(prev->right) prev = prev->right;
            
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        
        cur = cur->right;
    }
}

//TC->O(N)
//SC->O(1)

// void flatten(TreeNode* root) {
//     if(root == NULL)
//         return;
    
//     flatten(root->left);
//     flatten(root->right);
//     if(root->left){
//         TreeNode *right = root->right;
//         root->right = root->left;
//         root->left = NULL;
//         while(root->right) root = root->right;
//         root->right = right;
//     }
// }

// TreeNode *prev = NULL;
// void flatten(TreeNode* root) {
    
//     if(root == NULL) return;
    
//     flatten(root->right);
//     flatten(root->left);
    
//     root->right = prev;
//     root->left = NULL;
//     prev = root;
// }

//TC->O(N)
//SC->O(N)

// void flatten(TreeNode *root)
// {
//     if (root == NULL) return;

//     stack<TreeNode *> st;
//     st.push(root);
//     while (!st.empty())
//     {
//         TreeNode *cur = st.top();
//         st.pop();

//         if (cur->right)
//             st.push(cur->right);
//         if (cur->left)
//             st.push(cur->left);

//         if (!st.empty())
//             cur->right = st.top();
//         cur->left = NULL;
//     }
// }
//TC->O(N)
//SC->O(N)


void inorder(TreeNode *root)
{
    if(root == NULL) return;
    cout<<root->data<<"\n";
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    /*    1
        /   \
       2     5
      / \     \
     3   4     6 */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    cout << "The Inorder traversal after flattening binary tree \n";
    inorder(root);
    return 0;
}