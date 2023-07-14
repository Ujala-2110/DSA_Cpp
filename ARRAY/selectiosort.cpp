#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int minindex, temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        minindex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}
