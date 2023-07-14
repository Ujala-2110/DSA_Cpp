#include <stdio.h>

void reversearray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end]; //Swapping code.
        arr[end] = temp;
        start++;
        end--;
    }
}
void printarray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {2, 6, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    printf("Array before reversal\n");
    printarray(arr, n);
    reversearray(arr, 0, n - 1);
    printf("Reversed Array\n");
    printarray(arr, n);
    return 0;
}