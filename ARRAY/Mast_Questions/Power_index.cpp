// Problem Statement

// You are given an array 'A' of length 'N'. The power of any index 'i' is the number of index 'j' ('i' != 'j') such that 'A[i]' == 'A[j]' and ( (|i - j|) % A[i] ) == 0.
// Return the sum of the power of all the indexes.

// For Example:-
// Let 'N' = 5, 'A' = [2, 3, 2, 1, 3].
// The power of index 1 is 1.
// The power of index 2 is 1.
// The power of index 3 is 1.
// The power of index 4 is 0.
// The power of index 5 is 1.
// So our answer is 4.

// (i % A[i]) == (j % A[i])

#include<bits/stdc++.h>
using namespace std;

int poweredIndex(vector<int> arr){

    map<pair<int,int>,int>mp;

    for(int i=0;i<arr.size();i++)
    {
        mp[{arr[i], i % arr[i]}]++;
    }

    int ans = 0;

    for(auto it : mp){
        ans += (it.second * (it.second - 1));
    }

    return ans;
}

