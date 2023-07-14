// Method 2 (Search from root)
// Parent pointer is NOT needed in this algorithm. The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

// Input: node, root // node is the node whose Inorder successor is needed.

// Output: succ // succ is Inorder successor of node.

// If right subtree of node is not NULL, then succ lies in right subtree. Do the following.
// Go to right subtree and return the node with minimum key value in the right subtree.
// If right subtree of node is NULL, then start from the root and use search-like technique. Do the following.
// Travel down the tree, if a node's data is greater than root's data then go right side, otherwise, go to left side.

// C++ program for above approach
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *minValue(struct node *node);

struct node *inOrderSuccessor(struct node *root, struct node *n)
{

    // Step 1 of the above algorithm
    if (n->right != NULL)
        return minValue(n->right);

    struct node *succ = NULL;

    // Start from root and search for
    // successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }

    return succ;
}

// Given a non-empty binary search tree,
// return the minimum data value found
// in that tree. Note that the entire
// tree does not need to be searched.
struct node *minValue(struct node *node)
{
    struct node *current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Helper function that allocates a new
// node with the given data and NULL left
// and right pointers.
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return (node);
}

// Give a binary search tree and a
// number, inserts a new node with
// the given number in the correct
// place in the tree. Returns the new
// root pointer which the caller should
// then use (the standard trick to
// avoid using reference parameters).
struct node *insert(struct node *node, int data)
{

    /* 1. If the tree is empty, return a new,
       single node */
    if (node == NULL)
        return (newNode(data));
    else
    {
        struct node *temp;

        /* 2. Otherwise, recur down the tree */
        if (data <= node->data)
        {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else
        {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }

        /* Return the (unchanged) node pointer */
        return node;
    }
}

// Driver code
int main()
{
    struct node *root = NULL, *temp, *succ, *min;

    // Creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;

    // Function Call
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
        cout << "\n Inorder Successor of " << temp->data << " is " << succ->data;
    else
        cout << "\n Inorder Successor doesn't exit";

    getchar();
    return 0;
}
