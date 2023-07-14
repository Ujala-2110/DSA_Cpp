#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
{

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;

    // 20 20 18 15 11 9 7 0
    // 17 16 16 13  7 7 5 3

    // desired
    //  37 37 36 36 36 36 35 34

    // 37 37 36 36 36 36 36 36

    vector<int> ans;
    map<pair<int, int>, int> mp;

    pq.push({a[0] + b[0], {0, 0}});
    mp[{0, 0}] = 1;

    while (k--)
    {
        int top = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        ans.push_back(top);
        pq.pop();

        if (j + 1 < n && mp[{i, j + 1}] == 0)
        {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
            mp[{i, j + 1}] = 1;
        }

        if (i + 1 < n && mp[{i + 1, j}] == 0)
        {
            pq.push({a[i + 1] + b[j], {i + 1, j}});
            mp[{i + 1, j}] = 1;
        }
    }

    return ans;
}