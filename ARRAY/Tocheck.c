#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// void SelectionSort(int arr[], int n)
// { 
//     int index, temp;
//     for (int i = 0; i < n - 1; i++) //(n-1) pass
//     {
//         index = i;
//         for (int j = i + 1; j < n; j++)
//             if (arr[j] < arr[index])
//             {
//                 index = j;
//             }

//         temp = arr[i];
//         arr[i] = arr[index];
//         arr[index] = temp;
//     }
// }

void InsertionSort(int arr[], int n)
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
    int arr[] = {9, 11, 5, 2, 6, 8};
    int n = sizeof(arr) / sizeof(int);

    printarray(arr, n);
    InsertionSort(arr, n);
    printarray(arr, n);
    return 0;
}