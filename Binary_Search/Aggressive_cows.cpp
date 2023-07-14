#include <bits/stdc++.h>
using namespace std;

bool Check(vector<int> &arr, int d, int k)
{
    int n = arr.size();
    int cows = 1;
    int cord = arr[0]; // first cow is placed at arr[0]

    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - cord) >= d)
        {
            cows++;
            cord = arr[i];
        }

        if (cows >= k) return true;
    }

    return false;
}

/*
int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxD = arr[n - 1] - arr[0];
    int ans = 1;
    for (int d = 1; d <= maxD; d++) //we can improvise it using binary search
    {
        bool isPossible = Check(arr, d, k);
        if (isPossible)
        {
            ans = d;
        }
    }

    return ans;
}
//Brute force
//TC -> O(m*n) where m is search space
//Space Complexity: O(1)
*/

int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxD = arr[n - 1] - arr[0];
    int ans = 1;

    int low = 1, high = maxD;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (Check(arr, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }

        else high = mid - 1;
    }

    return ans;
}
//Using Binary search
// Time Complexity: O(N*log(M)). 
// Reason: For binary search in a space of M, O(log(M))  and for each search, we iterate over max N stalls to check. O(N).
// Space Complexity: O(1)

int main()
{
    vector<int> inp{1, 2, 8, 4, 9};
    int k = 3;
    cout << "The largest minimum distance is " << aggressiveCows(inp, k) << '\n';
    return 0;
}