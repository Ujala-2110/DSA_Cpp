// An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search. Below is an observation on the input array. 
// ** All elements before the required have the first occurrence at even index (0, 2, ..) and the next occurrence at odd index (1, 3, …). And all elements after the required elements have the first occurrence at an odd index and the next occurrence at an even index. ** 
// 1) Find the middle index, say ‘mid’.
// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ and else before mid.
// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ and else before mid.

// Below is the implementation based on the above idea: 

#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l ,int h)
{
    if(l > h) return -1;

    if(l == h) return arr[l];

    int mid = (l+h)/2;

    if(mid % 2 == 0)
    {
        if(arr[mid] == arr[mid+1]) search(arr,mid+1,h);
        else search(arr,l,mid);
    }

    else
    {
        if(arr[mid] == arr[mid-1]) search(arr,mid+1,h);
        else search(arr,l,mid);
    }
}

// T.C -> O(logn)
// S.C -> O(1)

int main()
{
    int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);
 
    cout << search(arr, 0, len - 1);
 
    return 0;
}
 