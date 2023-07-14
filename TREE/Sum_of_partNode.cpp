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

int sumOfParentOfXUtil(Node *root, int x)
{
    queue<Node *> q;
    if (root == NULL)
        return -1;
    q.push(root);
    int sum = 0;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if(temp->left->data == x)
            sum += temp->data;
            q.push(temp->left);
        }
        if (temp->right)
        {
            if(temp->right->data == x)
            sum += temp->data;
            q.push(temp->right);
        }
    }
    return sum;
}

int main()
{
    // binary tree formation
    Node *root = new Node(4);        /*        4        */
    root->left = new Node(2);        /*       / \       */
    root->right = new Node(5);       /*      2   5      */
    root->left->left = new Node(7);  /*     / \ / \     */
    root->left->right = new Node(2); /*    7  2 2  3    */
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    int x = 2;

    cout << "Sum = " << sumOfParentOfXUtil(root, x);

    return 0;
}