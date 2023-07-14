#include <bits/stdc++.h> 
using namespace std;

struct TrieNode{
    TrieNode *child[26];
    bool isEnd = false;
};

TrieNode *root;

class Trie{
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string &key)
    {
        TrieNode *curr = root;

        for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            if(curr->child[index] == NULL) curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    string search(string &key)
    {
        TrieNode *curr = root;
        string x = "";
        for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            curr =curr->child[index];

            if(curr->isEnd == true) x += key[i];
            else return x;
        }

        return x;
    }

    string func(int n, vector<string>&a)
    {
        //insert
        for(int i=0;i<n;i++)
        {
            insert(a[i]);
        }

        //search
        int cnt = 0;
        string ans = "";
        for(auto it : a) {
            string res = search(it);
            if(res.size() > cnt){
                cnt = res.size();
                ans = res;
            }
            
            else if(res.size() == cnt)
            {
                if(res < ans) ans = res;
            }
        }

        if(ans.size() >= 1) return ans;
        else return "None";
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie op;
    return op.func(n,a);
}


//Method->2
/*
    Time Complexity : O(Sum(A[i])*max(A[i])*log(N))
    Space Complexity : O(Sum(A[i]))

    where 'Sum(A[i])' is the sum of size of all words 'A[i]',
    'max(A[i])' is the maximum size of string in array 'A'.
    and 'N' is the size of array 'A'.
*/
#include<map>

string completeString(int n, vector<string> &a) {

    string ans = "";

    map<string,int> mp;

    // Storing all strings in hashmap.
    for (int i = 0; i < n; i++) {
      mp[a[i]] = 1;
    }

    for (int i = 0; i < n; i++) {
      string pre = "";
      bool flag = true;
      // Traversing over all prefixes of the string 'a[i]'.
      for (int j = 0; j < a[i].size(); j++) {
        pre += a[i][j];
        // If current prefix is not present in map, this string is invalid.
        if (mp.count(pre));
        else {
          flag = false;
          break;
        }
      }

      // Current string is a valid string.
      if (flag) {
        // If current string is longer than ans, we update it.
        if (ans.size() < a[i].size()) {
          ans = a[i];
        }
        // If current string is of same size as 'ans', but lexicographically smaller, we update it.
        else if (ans.size() == a[i].size() && a[i] < ans) {
          ans = a[i];
        }
      }
    }

    // If there is no valid answer, we return "None".
    if (ans.size() == 0) {
      ans = "None";
    }
    // Return the final result.
    return ans;
}




