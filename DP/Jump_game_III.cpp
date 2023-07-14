// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
// Notice that you can not jump outside of the array at any time.

// Example 1:

// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation: 
// All possible ways to reach at index 3 with value 0 are: 
// index 5 -> index 4 -> index 1 -> index 3 
// index 5 -> index 6 -> index 4 -> index 1 -> index 3 

// Example 2:

// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.

// It will fall in infinite loop 


#include<bits/stdc++.h>
using namespace std;

//Normal Dfs

bool func(int ind, vector<int>&arr , int n)
{
    if(ind < 0 || ind >= n || arr[ind] < 0) return 0;
    
    if(arr[ind] == 0) return 1;

    arr[ind] = - arr[ind];

    return (func(ind-arr[ind] , arr , n) | func(ind+arr[ind] , arr , n));
}

bool canReach(vector<int>& arr, int start) {
    
    int n = arr.size();
    return func(start, arr, n);
}

//Bfs

bool canReach(vector<int>& A, int cur) {
    queue<int> q;
    q.push(cur);
    while(size(q)) {
        cur = q.front(); q.pop();
        if(A[cur] == 0) return true;                        // target reached
        if(A[cur] < 0)  continue;                           // already visited - stop further exploration of this path
        if(cur + A[cur] < size(A)) q.push(cur + A[cur]);    // try forward jump
        if(cur - A[cur] >= 0)      q.push(cur - A[cur]);    // try backward jump
        A[cur] *= -1;                                       // mark current index as visited by negating
    }
    return false;             // explored all array without reaching target
}


// --> When we need to find minimum in these cases try to use bfs
// Bfs 
 int minJumps(vector<int>& arr) {
        
    int n = arr.size();
    map<int,vector<int>>index;

    for(int i=0;i<n;i++) index[arr[i]].push_back(i);

    vector<int>vis(n+1,0);

    queue<pair<int,int>>q;
    q.push({0,0});

    while(!q.empty())
    {
        int sz = q.size();

        for(int i=0;i<sz;i++)
        {
            int ind = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(ind == n-1) return steps;

            vis[ind] = 1;

            if(ind-1 >= 0 && !vis[ind-1]) q.push({ind-1,steps+1});
            if(ind+1 < n && !vis[ind+1]) q.push({ind+1,steps+1});

            for(auto it : index[arr[ind]])
            {
                if(it != ind && !vis[it]) q.push({it,steps+1});
            }

            index[arr[ind]].clear(); // Why to clear map
        }
    }

    return -1;
}


/*    Reason to clear the map   */

// Why to clear the map when you already marked "visited = true"?????
// #"Visited = true", will work completely fine to prevent visiting any index that is
// (already explored) or (waiting in the queue to be explored)
// #So whenever we iterate the "map" of similar valued indexes we can check whether the
// index is visited. If visited it will not consider that path.

// //========================================================================
// #But there is one problem of time constraint with the traditional approach
// #There could be a large number of indexes with same value
// #So after the first index for a value is encountered we add all the occurances of that value in the queue
// and mark those indexes as visited
// #When we encounter that similar valued index (after popping from queue) then we
// again iterate over all those redundant indexes and
// every time the condition "visited = true" becomes true and we just iterate those
// large number of indexes for no reason
// #So we can prevent this redundant iteration just by "CLEARING THE MAP FOR ALREADY VISITED VALUES"