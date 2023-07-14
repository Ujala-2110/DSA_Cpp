// N horizontal line segments are arranged on the X-axis of a 2D plane. The start and end point of each line segment is given in a Nx2 matrix lines[ ][ ]. Your task is to find the maximum number of intersections possible of any vertical line with the given N line segments.

// Example 1:

// Input:
// N = 4
// lines[][] = {{1,3}, {2,3}, {1,2}, {4,4}}
// Output:
// 3
// Explanation:
// A vertical line at X = 2 passes through 
// {1,3}, {2,3}, {1,2}, ie three of the 
// given horizontal lines.


#include<bits/stdc++.h>
using namespace std;

int maxIntersections(vector<vector<int>> lines, int n) {

    map<int,int>mp;
    int ans = 1;
    
    for(auto it : lines)
    {
        int a = it[0];
        int b = it[1]+1;
        
        mp[a]++;
        mp[b]--;
    }
    
    int sum = 0;
    
    for(auto it : mp)
    {
        sum += it.second;
        ans = max(ans , sum);
    }
    
    return ans;
}