// Akku likes binary numbers and she likes playing with these numbers. Her teacher once gave her a question.For given value of  L and R, Akku have to find the count of number X, which have only three-set bits in it's binary representation such that "L ≤ X ≤ R".Akku is genius, she solved the problem easily. Can you do it ??

// Example 1:

// Input:
// L = 11 and R = 19 
// Output: 4
// Explanation:
// There are 4 such numbers with 3 set bits in 
// range 11 to 19.
// 11 -> 1011
// 13 -> 1101
// 14 -> 1110
// 19 -> 10011

#include<bits/stdc++.h>
using namespace std;

vector<long long>ans;
void precompute()
{
    for(int i=0;i<63;i++)
    {
        for(int j=i+1;j<63;j++)
        {
            for(int k=j+1;k<63;k++)
            {
                long long curr = 0;
                
                curr |= 1ll << i;
                curr |= 1ll << j;
                curr |= 1ll << k;
                
                ans.push_back(curr);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
}

long long solve(long long l, long long r){
    // Code Here

    // long long up = lower_bound(ans.begin(),ans.end(),r) - ans.begin();
    long long up = upper_bound(ans.begin(),ans.end(),r) - ans.begin();
    long long lo = lower_bound(ans.begin(),ans.end(),l) - ans.begin();
    
    // auto it = find(ans.begin(), ans.end(), r);
    // if(it != ans.end()) return up-lo+1;
    return up-lo;
}