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

Node *insert(Node *root, int val)
{
    if (root == NULL) return new Node(val);

    if (root->data < val)
        root->left = insert(root->left, val);

    else if (root->data > val)
        root->right = insert(root->right, val);

    return root;
}

void kthLargestUtil(Node *root, int k, int &c)
{
    if (root == NULL || c >= k) return;

    kthLargestUtil(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is " << root->data << endl;
        return;
    }

    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;

    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int k = 5;
    kthLargest(root, k);

    return 0;
}