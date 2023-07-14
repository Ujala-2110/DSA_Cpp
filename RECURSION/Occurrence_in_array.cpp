#include <iostream>
using namespace std;

int LastOccur(int arr[], int n, int k)
{
    if (n == 0)
        return -1;

    if (arr[n - 1] == k)
        return (n - 1);

    return LastOccur(arr, n - 1, k);
}

int FirstOccur(int arr[], int n,int i, int k)
{
    if(i==n)
    return -1;

    if(arr[i]==k)
    return i;

    return FirstOccur(arr,n,i+1,k);
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    cout << LastOccur(arr, n, k) << "\n";
    cout << FirstOccur(arr, n, 0, k);
    return 0;
}
