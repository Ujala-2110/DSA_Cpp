#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int isBSTUtil(node* node, int min, int max);

int isBST(node* node)
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
	/* an empty tree is BST */
	if (node==NULL)
		return 1;
			
	/* false if this node violates
	the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;
	
	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return
		isBSTUtil(node->left, min, node->data) && // Allow only distinct values
		isBSTUtil(node->right, node->data, max); // Allow only distinct values
}


// long prev = -1e18;
// bool isValidBST(Node* root) {
                
//     if(root == NULL) return true;
    
//     if(!isValidBST(root->left)) return false;
//     if(prev >= root->val) return false;
    
//     prev = root->val;
//     return isValidBST(root->right);
// }
// Time Complexity: O(N), As we visit every node just once
// Auxiliary Space: O(h), Here h is the height of the tree and the extra space is used due to the function call stack. 

int main()
{
	node *root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);
	
	if(isBST(root))
		cout<<"Is BST";
	else
		cout<<"Not a BST";
		
	return 0;
}
