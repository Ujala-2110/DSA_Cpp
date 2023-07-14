#include <bits/stdc++.h>
using namespace std;

vector<int> secondGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int>nge(n,n) , ans(n);
    stack<int>s;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && nums[s.top()] <= nums[i]) s.pop();
        if(!s.empty()) nge[i] = s.top();
        s.push(i);
    }
    
    for(int i=0;i<n;i++)
    {
        int l = nge[i] + 1;
        
        while(l < n && nums[l] <= nums[i]) l = nge[l];
        if(l >= n) ans[i] = -1;
        else ans[i] = nums[l];
    }
    
    return ans;     
}

// vector<int> secondGreaterElement(vector<int> &A)
// {
//     int n = A.size();
//     vector<int> res(n, -1), s1, s2, tmp;
//     for (int i = 0; i < n; ++i)
//     {
//         while (!s2.empty() && A[s2.back()] < A[i])
//             res[s2.back()] = A[i], s2.pop_back();
//         while (!s1.empty() && A[s1.back()] < A[i])
//             tmp.push_back(s1.back()), s1.pop_back();
//         while (!tmp.empty())
//             s2.push_back(tmp.back()), tmp.pop_back();
//         s1.push_back(i);
//     }
//     return res;
// }

// Intuition
// Next Greater Element canb resolved with one mono stack.
// Could we resolve this problem with mono stack?


// Explanation
// Use two stack s1 and s2.
// Similar to "Next Greater Element"
// s1 stores the index of elements
// that have not found their first greater element.

// s2 stores the index of elements
// that have found their first greater element,
// have not found their second greater element.

// For each a = A[i] in A
// We first compare the a with the tail elements in s2,
// pop all element smaller than a,
// because a is their second greater element.

// Then we compare the a with the tail elements in s1,
// move all elements smaller than a to the tail of s2,
// because a is their first greater element.

// We repeatly do this for all A[i] and finally return the result.


// Complexity
// All A[i] is pushed in s1 and s2 at most once.
// All A[i] is pushed in s1 and s2 at most once.

// Time O(n)
// Space O(n)


int main()
{
    vector<int>nums = {11, 13, 21, 3};

    vector<int>ans = secondGreaterElement(nums);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}
