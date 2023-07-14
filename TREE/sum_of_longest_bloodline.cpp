// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)

// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//mst chij tha ye
void calculate_sum(Node *root,int &ans,int &maxlen,int len, int sum)
{
    if(root == NULL){
        
        if(len > maxlen){
            maxlen = len;
            ans = sum;
        }
        
        else if(len==maxlen){
            ans=max(ans,sum);
        }
        
        return;
    }
    
    calculate_sum(root->left,ans,maxlen,len+1,sum+root->data);
    calculate_sum(root->right,ans,maxlen,len+1,sum+root->data);
}
    
int sumOfLongRootToLeafPath(Node *root)
{
    int ans = INT_MIN;

    int maxlen = 0;
    int len = 0;
    int sum = 0;
    
    calculate_sum(root,ans,maxlen,len,sum);
    return ans;
}