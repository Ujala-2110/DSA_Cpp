// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (!root) return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int sz = q.size();
        int mini = q.front().second;
        int first, last;

        for (int i = 0; i < sz; i++)
        {
            int curr_id = q.front().second - mini;
            TreeNode *curr = q.front().first;
            q.pop();

            if (i == 0) first = curr_id;
            if (i == sz - 1) last = curr_id;

            if (curr->left)
                q.push({curr->left, (long long)2 * curr_id + 1});
            if (curr->right)
                q.push({curr->right, (long long)2 * curr_id + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(22);
    root->right->right = new TreeNode(25);

    cout<<widthOfBinaryTree(root);

    return 0;
}