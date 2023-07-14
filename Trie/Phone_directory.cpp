// C++ Program to Implement a Phone
// Directory Using Trie Data Structure
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isLast;
};

TrieNode *root = NULL;

class Trie
{
    public:
     
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }

        curr->isLast = true;
    }

    void insertIntoTrie(string s[], int n)
    {
        for (int i = 0; i < n; i++) insert(s[i]);
    }

    void displayContactsUtil(TrieNode *curNode, string prefix, vector<string> &vec)
    {
        if (curNode->isLast) vec.push_back(prefix);
        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode *nextNode = curNode->child[i - 'a'];
            if (nextNode != NULL) displayContactsUtil(nextNode, prefix + (char)i, vec);
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode *prevNode = root;
        vector<vector<string>> res;
        string prefix = "";
        int len = s.length();
        int i;
        for (i = 0; i < len; i++)
        {
            vector<string> v;
            prefix += (char)s[i];
            char lastChar = prefix[i];
            TrieNode *curNode = prevNode->child[lastChar - 'a'];
            if (curNode == NULL)
            {
                v.push_back("0");
                res.push_back(v);
                i++;
                break;
            }
            displayContactsUtil(curNode, prefix, v);
            prevNode = curNode;
            res.push_back(v);
        }
        for (; i < len; i++)
        {
            vector<string> v;
            v.push_back("0");
            res.push_back(v);
        }
        return res;
    }
};

int main()
{
    string contacts[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = sizeof(contacts) / sizeof(string);
    Trie op;
    op.insertIntoTrie(contacts, n);

    string query = "geeips";
    vector<vector<string>> ans = op.displayContacts(n, contacts, query);
    for (auto it : ans)
    {
        for (auto ch : it)
            cout << ch << " ";
        cout << "\n";
    }
    return 0;
}
