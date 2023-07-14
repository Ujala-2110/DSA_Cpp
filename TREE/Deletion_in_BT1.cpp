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

void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *deletion(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
    // and parent of deepest node(last)
    Node *key_node = NULL;
    Node *temp;
    Node *last;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left)
        {
            last = temp; //storing the parent node
            q.push(temp->left);
        }
        if (temp->right)
        {
            last = temp; //storing the parent node
            q.push(temp->right);
        }
    }
    if (key_node != NULL)
    {
        key_node->data = temp->data; //replacing key_node's data to deepest node's data
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    }
    return root;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right = new Node(8);

    cout << "Inorder traversal before deletion : ";
    inorder(root);

    int key = 7;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}