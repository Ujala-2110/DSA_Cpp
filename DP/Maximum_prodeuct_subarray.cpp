#include <bits/stdc++.h>
using namespace std;

/*
int max_product(int arr[], int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int pr = 1;
        for (int j = i; j < n; j++)
        {
            pr = pr * arr[j];
            ans = max(ans, pr);
        }
    }
    return ans;
}
T.C -> O(n^2)
*/
/*
long long max_product(int nums[], int n)
{
    
    long long ans = nums[0];
    long long ma = nums[0], mi = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0) // swapping because after multiplication with negative no. ma will become minimum and mi will become maximum
            swap(ma, mi);

        ma = max(nums[i] * 1LL, ma * nums[i]); // Two option either we can start fresh (nums[i]) or continue (ma*nums[i])
        mi = min(nums[i] * 1LL, mi * nums[i]); // Two option either we can start fresh (nums[i]) or continue (mi*nums[i])

        ans = max(ans, ma);
    }

    return ans;
}
// T.C -> O(n)
// S.C -> O(1)
*/
int max_product(int arr[] , int n)
{
    long product = 1;
    long maxproduct = arr[0];
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
        maxproduct = max(maxproduct, product);
        if (product == 0)
        {
            product = 1;
        }
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        product *= arr[i];
        maxproduct = max(maxproduct, product);
        if (product == 0)
        {
            product = 1;
        }
    }
    return maxproduct;
}

// T.C -> O(n)
// S.C -> O(1)

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_product(arr, n) << endl;
    return 0;
}