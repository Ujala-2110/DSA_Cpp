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
        left = NULL, right = NULL;
    }
};

class NodeValue
{
public:
    int maxN, minN, mxsize;

    NodeValue(int minN, int maxN, int mxsize)
    {
        this->maxN = maxN;
        this->minN = minN;
        this->mxsize = mxsize;
    }
};

NodeValue largestBstinBt(Node *root)
{
    // An empty tree is a bst of size 0
    if (root == NULL)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Get values from left and right subtree of current tree
    auto left = largestBstinBt(root->left);
    auto right = largestBstinBt(root->right);

    // Current node is greater than max in left && smaller than min in right, it is a bst
    if (left.maxN < root->data && root->data < right.minN)
    {
        // It is a bst
        return NodeValue(min(root->data, left.minN), max(root->data, right.maxN), left.mxsize + right.mxsize + 1);
    }

    // Otherwise return [INT_MIN,INT_MAX] so that parent can't be a valid bst
    return NodeValue(INT_MIN, INT_MAX, max(left.mxsize, right.mxsize));
}

// 

int main()
{
    /* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */

    struct Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    printf(" Size of the largest BST is %d\n", largestBstinBt(root).mxsize);
    return 0;
}

// class NodeValue
// {
// public:
//     int maxN, minN, mxSum;

//     NodeValue(int minN, int maxN, int mxSum)
//     {
//         this->maxN = maxN;
//         this->minN = minN;
//         this->mxSum = mxSum;
//     }
// };

// NodeValue largestBstinBt(Node *root)
// {
//     // An empty tree is a bst of size 0
//     if (root == NULL)
//     {
//         return NodeValue(INT_MAX, INT_MIN, 0);
//     }

//     // Get values from left and right subtree of current tree
//     auto left = largestBstinBt(root->left);
//     auto right = largestBstinBt(root->right);

//     // Current node is greater than max in left && smaller than min in right, it is a bst
//     if (left.maxN < root->data && root->data < right.minN)
//     {
//         // It is a bst
//         sum = max(sum, root->data + left.mxSum + right.mxSum);
//         return NodeValue(min(root->data, left.minN), max(root->data, right.maxN), left.mxSum + right.mxSum + root->data);
//     }

//     // Otherwise return [INT_MIN,INT_MAX] so that parent can't be a valid bst
//     return NodeValue(INT_MIN, INT_MAX, max(left.mxSum, right.mxSum));
// }
// int sum = 0;
// int maxSumBST(Node *root)
// {

//     largestBstinBt(root);
//     return sum > 0 ? sum : 0;
// }

//For Maximum Sum BST in Binary Tree