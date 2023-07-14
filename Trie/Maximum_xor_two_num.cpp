// Given an array of non-negative integers of size N. Find the maximum possible XOR between two numbers
// present in the array.

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

int max_xor(int arr[], int N)
{
    Trie op;

    for (int i = 0; i < N; i++)
    {
        op.insert(arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, op.getMax(arr[i]));
    }

    return ans;
}

int main()
{
    int input[] = {25, 10, 2, 8, 5, 3};
    int n = sizeof(input) / sizeof(int);
    cout << max_xor(input, n);

    return 0;
}