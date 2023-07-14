#include<bits/stdc++.h>
using namespace std;

//A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 


vector<int> diagonal(Node *root)
{
    vector<int>ans;
    if(root == NULL) return ans;
    
    queue<Node*> Q;
    Node *p;
    Q.push(root);
    while (!Q.empty())
    {
        p=Q.front();
        Q.pop();
        while (p)
        {
            if(p->left) Q.push(p->left);
            
            ans.push_back(p->data);
            p=p->right;
        }
    }
    
    return ans;
}
