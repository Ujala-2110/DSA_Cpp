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

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<int> s;
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        s.push(curr->data);
        q.pop();

        if (curr->right)
            q.push(curr->right);

        if (curr->left)
            q.push(curr->left);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
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

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}