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

// An iterative process to print preorder traversal of Binary tree
void iterativePostorder(Node *root)
{

  if (root == NULL)
    return;

  // Create two stacks
  stack<Node *> s1, s2;

  // push root to first stack
  s1.push(root);
  Node *node;

  // Run while first stack is not empty
  while (!s1.empty())
  {
    // Pop an item from s1 and push it to s2
    node = s1.top();
    s1.pop();
    s2.push(node);

    // Push left and right children
    // of removed item to s1
    if (node->left)
      s1.push(node->left);
    if (node->right)
      s1.push(node->right);
  }

  // Print all elements of second stack
  while (!s2.empty())
  {
    node = s2.top();
    s2.pop();
    cout << node->data << " ";
  }
}

int main()
{
  Node *root = NULL;
  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << "\nPreorder traversal of binary tree is \n";
  iterativePostorder(root);

  return 0;
}