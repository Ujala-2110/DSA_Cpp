#include <bits/stdc++.h>
using namespace std;

//we can solve this problem by sorting also which will take O(nlogn) time but using heap we can solve it in O(nlogk) time
void KLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;  //We nee to find largest that's why is used minheap

    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);

        if (minh.size() > k) minh.pop();
    }

    while (minh.size() > 0)
    {
        cout << minh.top() << " ";
        minh.pop();
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    KLargest(arr, n, k);
    return 0;
}