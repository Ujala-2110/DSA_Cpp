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

int findMax(Node *root)
{
    if (root == NULL) return -1;

    queue<Node *> q;
    q.push(root);

    int ans = 0;
    while (q.empty() == false)
    {
        Node *curr = q.front();
        ans = max(ans,curr->data);
        q.pop();

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
    return ans;
}
int main()
{
    Node *NewRoot = NULL;
    Node *root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);

    // Function call
    cout << "Maximum element is " << findMax(root) << endl;

    return 0;
}