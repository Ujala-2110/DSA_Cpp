#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll max_diff = LLONG_MIN;
pair<ll,ll> Getmaxdiff(int src , int parent,vector<vector<ll>>&graph , vector<ll>&w)
{
    if(parent != -1 && graph[src].size() == 1) //leaf node
    {
        return {w[src],w[src]};
    }

    pair<ll,ll>ans = {INT_MAX,INT_MIN};

    for(auto child : graph[src])
    {
        if(child != parent)
        {
            pair<ll,ll>chAns = Getmaxdiff(child,src,graph,w);
            ans.first = min(ans.first,chAns.first);
            ans.second = max(ans.second,chAns.second);
        }
    }

    max_diff = max({max_diff, w[src]-ans.first , ans.second-w[src]});
    ans.first = min(ans.first,w[src]);
    ans.second = max(ans.second,w[src]);
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> w(n);
    for (ll i = 0; i < n; i++) cin >> w[i];
    vector<vector<ll>> graph(n);
    ll parent, root;
    for (ll i = 0; i < n; i++)
    {
        cin >> parent;
        if (parent == -1)
        {
            root = i;
            continue;
        }
        graph[parent - 1].push_back(i);
        graph[i].push_back(parent-1);
    }
    
    Getmaxdiff(root,-1,graph,w);
    cout << max_diff;
    return 0;
}

// Family Tree Problem Code: FAMTREESolvedSubmit
// You are given a family tree with N members numbered 1...N. Every person i, except for the founder of the family (root) has a parent denoted by P[i]. P[root] = -1 by definition. Person i is a descendant of person j if i belongs to the subtree rooted at j.

// The net worth (adjusted for inflation) is given for all the members of the family. Your task is to find the maximum difference in net worth's of two members where one member is a descendant of the other.

// You can assume that no two members of this family married each other. So it remains a "family tree".

// Input:
// First line will contain an integer N, denoting the number of members.
// Second line contains N space seperated integers W[1], W[2] … W[N] denoting the net_worth of the N members.
// Third line contains N space seperated integers P[1], P[2] … P[N] denoting the parents of the N members.
// Output:
// Output in a single line the maximum difference in net worth's of any two members where one member is a descendant of the other.

// Constraints
// 2≤N≤105
// −108≤W[i]≤108
// 1≤P[i]≤N
// Sample Input:
// 4 
// 5 10 6 12 
// 2 -1 4 2 
// Sample Output:
// 6