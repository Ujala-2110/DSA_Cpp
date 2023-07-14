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

void inorder(Node *temp)
{
    if (temp == NULL) return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

Node *InsertNode(Node *root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }

    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = new Node(key);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = new Node(key);
            return root;
        }
    }
    return root;
}

// Driver code
int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = InsertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}