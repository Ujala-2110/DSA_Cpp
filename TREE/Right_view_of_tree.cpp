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

void Right_view(Node *root)
{
    if (!root) return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            // Print the left most element
            // at the level
            if (i == n)
                cout << temp->data << " ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
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
    root->right->left->right = new Node(8);

    Right_view(root);
    return 0;
}
