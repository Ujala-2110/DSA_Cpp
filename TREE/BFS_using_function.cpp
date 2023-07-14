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

int height(Node *root)
{
    if (root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1){
        cout << root->data << " ";
    }
    else if (level >1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}