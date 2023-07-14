#include <bits/stdc++.h>
using namespace std;

int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0) // Base case -> when the size of array will become 1 or 0
        return 1;

    //OR->  return (arr[n-1]>=arr[n-2] && arraySortedOrNot(arr,n-1));

    if (arr[n - 1] < arr[n - 2])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}

//Method->2
// bool sorted(int arr[], int n)
// {
//     if (n == 1)
//         return true;

//     return (arr[0] <= arr[1] && sorted(arr + 1, n - 1)); // arr+1 means the pointer will pass from arr[0] to arr[1] i mean to the next element
// }

int main()
{
    int arr[] = {20, 15, 23, 45, 78, 88};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (arraySortedOrNot(arr, n))
        cout << "Yes\n";
    else
        cout << "No\n";
}