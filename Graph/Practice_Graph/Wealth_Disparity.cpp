#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(ll v, vector<vector<ll>> &graph, vector<ll> &w, ll &ans, ll wealth)
{
    for (ll child : graph[v])
    {
        ans = max(ans, wealth - w[child]);
        dfs(child, graph, w, ans, max(w[child], wealth));
    }
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
    }
    ll ans = INT_MIN;
    dfs(root, graph, w, ans, w[root]);
    cout << ans;
    return 0;
}
