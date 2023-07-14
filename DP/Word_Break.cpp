#include <bits/stdc++.h>
using namespace std;

//Recursion
/*
bool func(string s, vector<string>& wordDict) {
    if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
        return true;

    for(int i=1;i<s.size();i++){
        string left = s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && func(s.substr(i),wordDict)){
            return true;
        }
    }
    return false;
}
*/

//Memoization
/*
bool func(string s, vector<string>& wordDict,map<string,bool>&mp) {
    if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()) return true;

    if(mp.find(s) != mp.end()) return mp[s];

    for(int i=1;i<s.size();i++){
        string left = s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && func(s.substr(i),wordDict,mp)){
            return mp[s] = true;
        }
    }
    return mp[s] = false;
}
*/

//Tabulation
bool func(string s, vector<string>& wordDict) {
    int len = s.length();
    vector<bool> dp(len+1,false);
    dp[0] = true;

    for(int i=1;i<=len;i++){
        for(int j=0;j<i;j++){
            if(dp[j] and find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                dp[i]=true;   
            }              
        }
    }
    return dp[len];
}

int main()
{
    vector<string> WordDict = {"i", "like", "sam","sung", "samsung", "mobile","ice", "cream", "icecream","man", "go", "mango"};
    string target = "ilike";

    // cout<<func(target,WordDict);
    //Memoization
    // map<string,bool>mp;
    // cout<<func(target,WordDict,mp);
    
    //Tabulation
    cout<<func(target,WordDict);
}