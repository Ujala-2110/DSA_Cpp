#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main()
{
    string pat = "ab";
    vector<int>prefix = prefix_function(pat);

    string str = "ggabcabcd";

    int pos = -1;
    int i = 0, j = 0;

    while(i < str.size())
    {
        if(str[i] == pat[j]){
            i++;
            j++;
        }

        else{
            if(j != 0) j = prefix[j-1];
            else i++;
        }

        if(j == pat.size()){
            pos = i - pat.size();
            break;
        }
    }

    cout<<pos<<"\n";
    return 0;
}