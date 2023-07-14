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

void Top_view(Node *root)
{
    map<int, int> m;
    queue<pair<Node *, int>> q;

    if (!root) return;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *t = q.front().first;
        int h = q.front().second;
        q.pop();
        
        if (!m[h])
            m[h] = t->data;
        if (t->left)
            q.push({t->left, h - 1});
        if (t->right)
            q.push({t->right, h + 1});
    }
    for (auto x : m)
        cout << x.second << " ";
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Top_view(root);
    return 0;
}
