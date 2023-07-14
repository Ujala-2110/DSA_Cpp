// Given an array of integers arr, you are initially positioned at the first index of the array.
// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.

 

// Example 1:

// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

#include<bits/stdc++.h>
using namespace std;

/*    Why DFS will not work (link -> https://leetcode.com/problems/jump-game-iv/solutions/1316467/jump-game-iv-why-dfs-will-not-work-explained/)       */


// So, we tried solving below problems:
// 1.) Multiple paths with common node : Used backtracking to mark and unmark the node.
// Its a bruteforce, will give TLE.

// 2.) Multiple paths from node x to last index : Used dp[x] to store computed value for a node x in a path. Will not work, as stored value may not be the min value. WA

//Backtracking
int func(int ind,vector<int>& arr,int n,map<int,vector<int>>&index,vector<int>&vis)
{
    if(ind < 0 || ind >= n) return 1e9;
    if(vis[ind] == 1) return 1e9;
    if(ind == n-1) return 0;

    int ans = 1e9;
    vis[ind] = 1;

    ans = min(ans + 0ll, 1ll + func(ind-1,arr,n,index,vis));
    ans = min(ans + 0ll, 1ll + func(ind+1,arr,n,index,vis));

    for(auto it : index[arr[ind]])
    {
        if(it != ind) ans = min(ans + 0ll, 1ll + func(it,arr,n,index,vis));
    }

    vis[ind] = 0;
    return ans;
}

int minJumps(vector<int>& arr) {
    
    int n = arr.size();
    map<int,vector<int>>index;

    for(int i=0;i<n;i++)
    {
        index[arr[i]].push_back(i);
    }

    vector<int>vis(n+1,0);
    return func(0,arr,n,index,vis);
}

// Why memoization will not work -> so we compute min path from one way and store it but there may be some other path (As we are backtracking) but will return only this so it will give us wrong answer