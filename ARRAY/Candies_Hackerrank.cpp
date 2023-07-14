// Problem
// Alice is a kindergarten teacher. She wants to give some candies to the children in her class. 
// All the children sit in a line and each of them has a rating score according to his or her performance in the class.
//  Alice wants to give at least 1 candy to each child. If two children sit next to each other, 
//  then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

// Example:

// arr = [ 4, 6, 4, 5, 6, 2]
// She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]
// She must buy a minimum of 10 candies.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Method -> 1
int main()
{

    ll n, i;
    cin >> n;
    ll ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    ll c = 0;
    ll sum = 0;
    for (i = 1; i < n; i++)
    {
        if (ar[i] > ar[i - 1])
        {
            c++;
        }
        else if (ar[i] == ar[i - 1])
        {
            sum++;
        }
        else
        {
            if (c > 0)
            sum += ((c + 2) * (c + 1)) / 2;
            c = 0;
        }
    }
    if (i >= n && c > 0) sum += ((c + 2) * (c + 1)) / 2;

    // cout<<sum<<endl;
    c = 0;
    for (i = 1; i < n; i++)
    {
        if (ar[i] < ar[i - 1])
        {
            c++;
        }
        else
        {
            if (c > 1)
            {
                sum += (c * (c + 1)) / 2;
            }
            c = 0;
        }
    }
    if (c > 1)
    {
        sum += (c * (c + 1)) / 2;
    }

    cout << sum << endl;
    // }
    return 0;
}

//Method -> 2
long candies(int n, vector<int> arr)
{
    int val = 1;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = val;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            s[i] += s[i - 1];
        }
    }

    for (int i = n - 2; i > -1; i--)
    {
        if (arr[i] > arr[i + 1] && s[i] <= s[i + 1])
            s[i] = s[i + 1] + 1;
    }
    long sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += s[i];
    }

    return sum;
}

//Method -> 3
long candies(int n, vector<int> arr)
{
    vector<long> c(n, 1);

    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            c[i] = max(c[i], c[i - 1] + 1);

    for (int i = n - 1; i > 0; i--)
        if (arr[i] < arr[i - 1])
            c[i - 1] = max(c[i - 1], c[i] + 1);

    return accumulate(c.begin(), c.end(), 0LL);
}

//Method -> 4
signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1] and dp[i] <= dp[i - 1]) // checking for the left neighbour
        { 
            dp[i] = dp[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] and dp[i] <= dp[i + 1])  // checking for the right neighbour
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dp[i];
    }
    cout << sum << endl;
}