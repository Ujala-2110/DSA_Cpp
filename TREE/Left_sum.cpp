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

int leftLeavesSum(Node *root)
{
    queue<Node *> q;
    if (root == NULL) return -1;
    q.push(root);
    int sum = 0;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (temp->left->left == NULL && temp->left->right == NULL)
                sum += temp->left->data;
            q.push(temp->left);
        }
        if (temp->right)
        {
            if (temp->right->left == NULL && temp->right->right == NULL)
                sum += temp->right->data;
            q.push(temp->right);
        }
    }
    return sum;
}

int main()
{
    // Let us a construct the Binary Tree
    struct Node *root = new Node(20);
    root->left = new Node(9);
    root->right = new Node(49);
    root->right->left = new Node(23);
    root->right->right = new Node(52);
    root->right->right->left = new Node(50);
    root->left->left = new Node(5);
    root->left->right = new Node(12);
    root->left->right->right = new Node(12);
    cout << "Sum of left leaves is " << leftLeavesSum(root);
    return 0;
}