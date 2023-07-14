// 	Number of Distinct Substrings in a String using trie
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
};

int countDistinctSubstring(string s)
{
    TrieNode *root = new TrieNode();
    int cnt = 0;
    for(int i=0;i<s.length();i++)
    {
        TrieNode *curr = root;
        for(int j=i;j<s.length();j++)
        {
           if(curr->child[s[j]-'a'] == NULL)
           {
               cnt++;
               curr->child[s[j]-'a'] = new TrieNode();
           }
            
            curr = curr->child[s[j]-'a'];
        }
    }
    
    return cnt+1;
}


int main()
{
	int count = countDistinctSubstring("abc");

	cout << "Count of Distinct Substrings: " << count << endl;

	return 0;
}
