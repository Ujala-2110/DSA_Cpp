#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(int postorder[], int postst, int posted, int inorder[], int inst, int ined, map<int, int> &mp)
{
    if (postst > posted || inst > ined)
        return NULL;

    Node *root = new Node(postorder[posted]);

    int inroot = mp[root->data];
    int numsleft = inroot - inst;

    root->left = BuildTree(postorder, postst, postst + numsleft - 1, inorder, inst, inroot - 1, mp);
    root->right = BuildTree(postorder, postst + numsleft, posted - 1, inorder, inroot + 1, ined, mp);

    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);

    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    Node *root = BuildTree(post, 0, n - 1, in, 0, n - 1, mp);
    // To print traverse through any traversal
    preOrder(root);
    return 0;
}