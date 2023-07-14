#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[2];
};

class Trie
{

private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (curr->child[bit] == NULL)
                curr->child[bit] = new TrieNode();

            curr = curr->child[bit];
        }
    }

    int getMax(int num)
    {
        TrieNode *curr = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (curr->child[1 - bit] != NULL)
            {
                maxi = maxi | (1 << i);
                curr = curr->child[1 - bit];
            }
            else
            {
                curr = curr->child[bit];
            }
        }

        return maxi;
    }
};

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> oq; //Offline queries -> ordered are jumbled wrt original one

    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        oq.push_back({queries[i][1], {queries[i][0], i}});
    }

    //O(qlog(q))
    sort(oq.begin(), oq.end());

    vector<int> ans(q, 0);
    int ind = 0;
    int n = nums.size();

    Trie op;

    //O(q*32 + n*32) => O(q+n)*32
    for (int i = 0; i < q; i++)
    {
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int qind = oq[i].second.second;

        while (ind < n && nums[ind] <= ai)
        {
            op.insert(nums[ind]);
            ind++;
        }

        if (ind == 0)
            ans[qind] = -1;
        else
            ans[qind] = op.getMax(xi);
    }

    return ans;
}


int main()
{
    vector<int>arr = {0,1,2,3,4};
    vector<vector<int>>queries = {{3,1},{1,3},{5,6}};
    vector<int>ans = maximizeXor(arr,queries);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}