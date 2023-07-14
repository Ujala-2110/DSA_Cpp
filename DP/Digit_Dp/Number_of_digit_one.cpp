// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// Example 1:

// Input: n = 13
// Output: 6

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int arr[1001];
ll dp[11][1000][2];

ll getSum(int pos, int n, ll sum , bool flag)
{
    if(pos > n) return sum;

    if(dp[pos][sum][flag] != -1) return dp[pos][sum][flag];

    int lim = 9;
    if(!flag) lim = arr[pos];

    ll res = 0;
    for(int i=0;i<=lim;i++)
    {
        if(flag || i < lim) res += getSum(pos+1,n,sum +(i == 1) , true);
        else res += getSum(pos+1, n , sum + (i == 1) , false);
    }

    return dp[pos][sum][flag] = res;
}

int countDigitOne(int n) {
    
    string a = to_string(n);

    for(int i=0;i<a.size();i++) arr[i+1] = a[i] - '0';
    memset(dp, -1 , sizeof(dp));

    return getSum(1,a.size(),0,0);
}

//Another approach

// link -> (https://drive.google.com/file/d/1aOngbbER-vHBdXWkVcxnzTU4iscmZXUB/view)

#define ll long long int
ll dp[11][1000][2];

int getsum(int ind,int tight, int n, int sum, string &s)
{
    if(ind >= n) return sum;

    if(dp[ind][sum][tight] != -1) return dp[ind][sum][tight];

    int lo = 0;
    int hi = (tight) ? (s[ind] - '0') : 9;

    ll ans = 0;
    for(int idx = lo; idx <= hi; idx++)
    {
        ans += getsum(ind+1,(tight & (idx == hi)),n,(sum + (idx == 1)),s); 
    }
    
    return dp[ind][sum][tight] = ans;
}

int countDigitOne(int n) {

    string s = to_string(n);
    int sz = s.length();

    memset(dp,-1,sizeof(dp));
    return getsum(0,1,sz,0,s);
}