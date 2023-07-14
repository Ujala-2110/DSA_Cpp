#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

//We know the low index and for finding the hingh index we traverse in loop until we get value higher than key
// int findPos(int arr[], int key)
// {
//     int l = 0, h = 1;

//     // Find h to do binary search
//     while (arr[h] < key)
//     {
//         l = h;        // store previous high in low
//         h = 2 * h;    // double high index
//     }

//     // at this point we have updated low and
//     // high indices, Thus use binary search
//     // between them
//     return binarySearch(arr, l, h, key);
// }

//Method->2
int findPos(int arr[], int x)
{
    if(arr[0] == x) return 0; 

    int i = 1;
    while(arr[i] < x)
    {
        i = i*2;
    }

    if(arr[i] == x) return i;
    return binarySearch(arr,(i/2)+1 , i-1, x);
}

// Driver program
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans == -1) cout << "Element not found";
    else cout << "Element found at index " << ans;
    return 0;
}
