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

int addBT(Node *root)
{
    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);
    int sum = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        sum += curr->data;
        q.pop();

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return sum;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    int sum = addBT(root);
    cout << "Sum of all the elements is: " << sum << endl;

    return 0;
}