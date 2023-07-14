#include <stdio.h>

void insertionsort(int arr[], int n)
{
    int key,i,j;
    for (i = 1; i <= n - 1; i++)        // For passes.
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && key<arr[j]; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {8, 126, 36, 45, 1};
    int n = sizeof(arr) / sizeof(int);
    insertionsort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}