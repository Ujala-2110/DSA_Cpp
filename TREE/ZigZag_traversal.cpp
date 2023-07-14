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

void zizagtraversal(Node *root)
{
    queue<Node *> q;
    vector<int> ans;

    if (root == NULL) return;
    q.push(root);
    int f = 1;

    while (!q.empty())
    {
        vector<int> temp;
        int s = q.size();
        while (s--)
        {
            Node *t = q.front();
            temp.push_back(t->data);
            q.pop();

            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        if (f % 2 == 0)
            reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);

        f++;
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}

int main()
{
    // create tree
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);

    return 0;
}