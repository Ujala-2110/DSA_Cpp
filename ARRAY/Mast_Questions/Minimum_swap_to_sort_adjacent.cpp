// Given an array arr[] of size N of non negative integers. We can perform a swap operation on any two adjacent elements in the array. The task is to find the minimum number of swaps needed to sort the array in non - decreasing order.
 
// Example 1:

// Input:
// N = 4
// arr[] = {4, 1, 2, 3}
// Output: 3
// Explanation: (4,1,2,3) -> (1,4,2,3) -> 
// (1,2,4,3) -> (1,2,3,4). Hence we need 
// a total of 3 swaps to sort it in 
// non - decreasing order.

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left ,int mid , int right)
{
    int i,j,k;
    int inv_cnt = 0;
    i = left;
    j = mid;
    k = left;

    while(i <= (mid-1) && j <= right)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_cnt = inv_cnt + (mid - i);
        }
    }

    while(i <= (mid - 1))
    temp[k++] = arr[i++];

    while(j <= right)
    temp[k++] = arr[j++];

    for(i = left ; i<= right ; i++)
    arr[i] = temp[i];

    return inv_cnt;
}

int merge_sort(int *arr , int temp[] , int left , int right)
{
    int mid, inv_cnt = 0;

    if(right > left)
    {
        mid = (right + left)/2;
        inv_cnt += merge_sort(arr,temp,left,mid);
        inv_cnt += merge_sort(arr,temp,mid+1,right);

        inv_cnt += merge(arr,temp,left,mid+1,right);
    }

    return inv_cnt;
}	

int countSwaps(int arr[], int n)
{
    int temp[n];
    int ans = merge_sort(arr, temp , 0, n-1);

    return ans;
}