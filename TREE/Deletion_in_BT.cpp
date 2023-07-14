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
//INCOMPLETE
void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int SearchDeepest(Node *root)
{
    if (root == NULL)
        return -1;
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        v.push_back(curr->data);
        if (curr->right)
            q.push(curr->right);
    }
    int n = v.size();
    return v[n - 1];
}

Node *Delete(Node *root)
{
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        v.push_back(curr->data);
        if (curr->right)
            q.push(curr->right);
        else
            delete curr;
    }
    return root;
}

Node *deletion(Node *root, int key)
{
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->data == key)
        {
            curr->data = SearchDeepest(root);
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    root = Delete(root);
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