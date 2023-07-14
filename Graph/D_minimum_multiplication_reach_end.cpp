// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Input:
// arr[] = {3, 4, 65}
// start = 7, end = 66175
// Output:
// 4
// Explanation:
// Step 1: 7*3 = 21 % 100000 = 21 
// Step 2: 21*3 = 6 % 100000 = 63 
// Step 3: 63*65 = 4095 % 100000 = 4095 
// Step 4: 4095*65 = 266175 % 100000 = 66175

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    const int mod = 100000;
    int n = arr.size();
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(1e5, 1e9);
    dist[start] = 0;

    //TC-> O(100000*n) but in real scenario it will depend and will be less than that
    while (!q.empty())
    {
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();

        if (node == end)
            return steps;

        for (int i = 0; i < n; i++)
        {
            int newNode = (node * arr[i]) % mod; // It is taking care that number is less than 100000

            if (steps + 1 < dist[newNode]) //we cannot write (newNode <= end) because it may happen that big number mutliplied with an array number and then after multiplication it gives the end value
            {
                q.push({steps + 1, newNode});
                dist[newNode] = steps + 1;
            }
        }
    }

    return -1;
}