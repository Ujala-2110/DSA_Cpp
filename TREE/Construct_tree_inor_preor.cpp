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

Node *BuildTree(int preorder[], int prest, int preed, int inorder[], int inst, int ined, map<int, int> &mp)
{
    if (prest > preed || inst > ined) return NULL;

    Node *root = new Node(preorder[prest]);

    int inRoot = mp[root->data];
    int numsleft = inRoot - inst;

    root->left = BuildTree(preorder, prest + 1, prest + 1 + numsleft, inorder, inst, inRoot - 1, mp);
    root->right = BuildTree(preorder, prest + 1 + numsleft, preed, inorder, inRoot + 1, ined, mp);

    return root;
}

int main()
{
    int in[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
    int pre[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};
    int n = sizeof(in) / sizeof(int);

    map<int, int> mp;

    for (int i = 0; i < n; i++) mp[in[i]] = i;

    Node *root = BuildTree(pre, 0, n - 1, in, 0, n - 1, mp);
    //To print traverse through any traversal

    return 0;
}