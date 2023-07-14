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

Node *insert(Node *root, int key)
{
    // Your code here
    if (root == NULL) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}
void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key) return root;

    if (key < root->data)
        return search(root->left, key);

    if (key > root->data)
        return search(root->right, key);
    return root;
}

Node *getsuc(Node *root)
{
    Node *p = root->right;
    while (p->left)
        p = p->left;

    return p;
}

Node *deleteNode(Node *root, int val)
{
    if (!root)
        return NULL;
    if (val > root->data)
        root->right = deleteNode(root->right, val);
    else if (val < root->data)
        root->left = deleteNode(root->left, val);
    else
    {
        if(!root->right)
        {
            Node * temp = root->left;
            delete(root);
            return temp;
        }
        else if(!root->left)
        {
            Node * temp = root->right;
            delete(root);
            return temp;
        }
        else
        {
            Node *suc = getsuc(root);

            swap(root->data, suc->data);
            root->right = deleteNode(root->right, val);
        }
    }

    return root;
}

int main()
{
    /* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}
