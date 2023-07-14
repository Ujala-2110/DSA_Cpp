
// Title --> Merging of Two Sorted arrays
// Algorithm --> Iterative
// Output--> 0,1,2,3,4,5

#include <stdio.h>

void Mergingarrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main()
{
    int arr1[] = {1, 2, 3};
    int n1 = sizeof(arr1) / sizeof(int);

    int arr2[] = {0, 4, 5};
    int n2 = sizeof(arr2) / sizeof(int);

    int arr3[n1 + n2];
    Mergingarrays(arr1, arr2, n1, n2, arr3);

    printf("After Merging arrays\n");
    for (int i = 0; i < n1 + n2; i++)
        printf("%d ", arr3[i]);

    return 0;
}