#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{
    int sum = 0, init = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > s)
        {
            while (sum > s)
            {
                sum = sum - arr[init];
                init++;
            }
        }

        if (sum == s)
        {
            v.push_back(init + 1);
            v.push_back(i + 1);
            break;
        }
    }

    if (v.size() == 0) v.push_back(-1);
    return v;
}

int main()
{
    int A[] = {1, 2, 3, 7, 5};
    int N = 5, S = 12;
    vector<int> res = subarraySum(A, N, S);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}