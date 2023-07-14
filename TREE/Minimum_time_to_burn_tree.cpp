// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.


// Example 1:

// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void markparent(Node *root, unordered_map<Node *,Node *>&parent, Node* &tar_node,int target)
{
    queue<Node *>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        
        if(curr->data == target){
            tar_node = curr;
        }
        
        if(curr->left){
            q.push(curr->left);
            parent[curr->left] = curr;
        }
        
        if(curr->right){
            q.push(curr->right);
            parent[curr->right] = curr;
        }
    }
}

int minTime(Node* root, int target) 
{
    unordered_map<Node *,Node *>parent;
    Node *tar_node = NULL;
    markparent(root,parent,tar_node,target); // mark the parent
    
    unordered_map<Node *,bool>vis;
    queue<Node *>q;
    
    q.push(tar_node);
    vis[tar_node] = true;
    int time = 0;
    
    while(!q.empty())
    {
        int sz = q.size();
        time++;
        
        for(int i=0;i<sz;i++)
        {
            Node *curr = q.front();
            q.pop();
            
            if(curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left] = true;
            }
            
            if(curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right] = true;
            }
            
            if(parent[curr] && !vis[parent[curr]])
            {
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }
    }
    
    return time-1;
}

// TC -> O(n)
// SC -> O(n)