// Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
// Note: You have to return list in sorted order.

// Example 1:

// Input:      
//           20
//         /    \
//       8       22 
//     /   \
//    4    12 
//        /   \
//       10    14
// Target Node = 8
// K = 2
// Output: 10 14 22
// Explanation: The three nodes at distance 2
// from node 8 are 10, 14, 22.


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
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

vector <int> KDistanceNodes(Node* root, int target , int k)
{
    unordered_map<Node *,Node *>parent;
    Node *tar_node = NULL;
    markparent(root,parent,tar_node,target); // mark the parent to go upside
    
    // cout<<tar_node<<" "<<tar_node->data <<" "<< target;
    
    unordered_map<Node *,bool>vis;
    queue<Node *>q;
    
    q.push(tar_node);
    vis[tar_node] = true;
    int curr_lev = 0;
    
    while(!q.empty())
    {
        int sz = q.size();
        if(curr_lev++ == k) break;
        
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
    
    vector<int>ans;
    
    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}

//steps
// 1-> mark the parent node so that we can traverse up and find the target node
// 2-> Do bfs in left , right and up dirction till the distance becomes k