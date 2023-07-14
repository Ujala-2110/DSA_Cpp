// Some robots are standing on an infinite number line with their initial coordinates given by a 0-indexed integer array nums and will start moving once given the command to move. The robots will move a unit distance each second.

// You are given a string s denoting the direction in which robots will move on command. 'L' means the robot will move towards the left side or negative side of the number line, whereas 'R' means the robot will move towards the right side or positive side of the number line.

// If two robots collide, they will start moving in opposite directions.

// Return the sum of distances between all the pairs of robots d seconds after the command. Since the sum can be very large, return it modulo 109 + 7.

// link -> [https://leetcode.com/problems/movement-of-robots/description/]
// link -> [https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/]

// --> Collision does't matter here because you cannot differentiate between two robos seems like they phased through each other

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

int sumDistance(vector<int> &nums, string s, int d)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') nums[i] += d;
        else nums[i] -= d;
    }

    ll ans = 0;
    ll pref = 0;

    sort(nums.begin(), nums.end()); // Why Sorting ?? -> [So that we can find the sum of pairs optimally using prefix sum]

    for (int i = 0; i < n; i++)
    {
        ans += i * 1ll * nums[i] - (pref);
        ans %= mod;
        pref += nums[i];
    }

    return ans;
}