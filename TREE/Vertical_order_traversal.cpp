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

// Using multimap

// vector<int> verticalOrderTraversal(TreeNode<int> *root)
// {
//     vector<int>ans;
//     if(!root) return ans;
//     multimap<int,int>mp;
//     queue<pair<TreeNode<int> *,int>>q;
//     q.push({root,0});

//     while(!q.empty())
//     {
//         TreeNode<int> *t = q.front().first;
//         int h = q.front().second;
//         q.pop();

//         mp.insert({h,t->data});
//         if(t->left) q.push({t->left,h-1});
//         if(t->right) q.push({t->right,h+1});
//     }

//     for(auto it : mp) ans.push_back(it.second);
//     return ans;
// }

void printVerticalOrder(Node *root)
{
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;

    if (!root) return;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *t = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h].push_back(t->data);
        if (t->left)
            q.push({t->left, h - 1});
        if (t->right)
            q.push({t->right, h + 1});
    }
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); ++i)
            cout << (it->second)[i] << " ";
        cout << endl;
    }
}

// vector<vector<int>> verticalTraversal(TreeNode *root)
// {

//     vector<vector<int>> ans;
//     if (root == NULL)
//         return ans;

//     // nodes -> to store vertical, level and nodes at that (vertical, level) point
//     map<int, map<int, multiset<int>>> nodes;

//     // todo -> to store node with respect to it's vertical and level
//     queue<pair<TreeNode *, pair<int, int>>> todo;

//     todo.push({root, {0, 0}});
//     while (!todo.empty())
//     {
//         auto p = todo.front();
//         todo.pop();
//         TreeNode *node = p.first;
//         int x = p.second.first;  // vertical
//         int y = p.second.second; // level

//         nodes[x][y].insert(node->val);

//         if (node->left)
//             todo.push({node->left, {x - 1, y + 1}});
//         if (node->right)
//             todo.push({node->right, {x + 1, y + 1}});
//     }

//     for (auto p : nodes)
//     {
//         vector<int> col;
//         for (auto i : p.second)
//         {
//             col.insert(col.end(), i.second.begin(), i.second.end());
//         }

//         ans.push_back(col);
//     }

//     return ans;
// }

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal is n";
    printVerticalOrder(root);
    return 0;
}