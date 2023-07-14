#include <bits/stdc++.h>
using namespace std;

// Dp on trees 

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

int height(Node *root, int &ans)
{
    if (root == NULL) return 0;

    int left_height = height(root->left, ans);

    int right_height = height(root->right, ans);

    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height); // agar ye khud ans banana chahta hai

    return 1 + max(left_height, right_height); //agar ye khud ans nhi banana chahta hai 
}

/* Computes the diameter of binary tree with given root. */
int diameter(Node *root)
{
    if (root == NULL) return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans;
}

int main()
{
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Function Call
    cout << "Diameter of the given binary tree is " << diameter(root);

    return 0;
}