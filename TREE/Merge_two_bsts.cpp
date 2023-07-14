#include <bits/stdc++.h> 
using namespace std;

// structure of binary tree
class TreeNode{

    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

//Approach - 1 ==> (merge two sorted arrays) and convert (sorted array to bst)

void inorder(TreeNode *root1 , vector<int>&ans)
{
    if(root1 == NULL) return;

    inorder(root1->left,ans);
    ans.push_back(root1->data);
    inorder(root1->right,ans);
}

void merge_two_sorted(vector<int>&first, vector<int>&second,vector<int>&ans)
{
    int n = first.size();
    int m = second.size();

    int i=0, j=0;

    while(i < n && j < m)
    {
        if(first[i] < second[j]) {
            ans.push_back(first[i]);
            i++;
        }

        else{
            ans.push_back(second[j]);
            j++;
        }
    }
    
    while(i < n){
        ans.push_back(first[i]);
        i++;
    }

    while(j < m){
        ans.push_back(second[j]);
        j++;
    }
}

TreeNode* Sorted_to_bst(int l, int h, vector<int>&ans)
{
    if(l > h) return NULL;

    int mid = (l + h) >> 1;

    TreeNode *root = new TreeNode(ans[mid]);

    root->left = Sorted_to_bst(l,mid-1,ans);
    root->right = Sorted_to_bst(mid+1,h,ans);

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    
    vector<int>first , second;

    inorder(root1,first);
    inorder(root2,second);

    vector<int>ans;
    merge_two_sorted(first,second,ans);

    return Sorted_to_bst(0,ans.size()-1,ans);
}


//***********************************************//

void BSTtoDDL(TreeNode *root, TreeNode *&head)
{
    if(root==NULL)return;
    
    BSTtoDDL(root->right,head);

    root->right=head;

    if(head!=NULL) head->left=root;
    
    head=root;

    BSTtoDDL(root->left,head);
}

TreeNode *mergeTwoDLL(TreeNode *head1, TreeNode *head2)
{

    TreeNode * head = NULL;
    TreeNode * tail = NULL;

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head;
                head1=head1->right;
            }

            else
            {
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }

        else{
            if(head==NULL)
            {
                head=head2;
                tail=head;
                head2=head2->right;
            }
            else
            {
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }

    while(head1!=NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    
    while(head2!=NULL)
    {
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }

    return head;
} 

int count(TreeNode *&head)
{
    int cnt=0;
    TreeNode *temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

TreeNode *DLLtoBST(TreeNode* &head,int n)
{
    if(n <= 0 || head == NULL) return NULL;

    TreeNode * left = DLLtoBST(head,n/2);

    TreeNode *root=head;
    root->left =left;
    head=head->right;

    root->right = DLLtoBST(head ,(n-n/2-1));

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
       
    //Steps to solve

    // 1. -> convert bst to sorted linked list 
    // 2. -> merge two sorted linked list
    // 3. -> convert sorted linked list to bst

    TreeNode *head1=NULL;
    TreeNode *head2=NULL;

    //convert BST to LL
    BSTtoDDL(root1,head1);
    head1->left=NULL;

    BSTtoDDL(root2, head2);
    head2->left=NULL;

    //merge two LL
    TreeNode *head=mergeTwoDLL(head1,head2);
    int n = count(head);

    //LL to BST
    TreeNode * root = DLLtoBST(head,n);
    return root;
}