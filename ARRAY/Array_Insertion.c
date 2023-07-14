// Title --> Insertion in array
// Algorithm --> Iterative
// Input --> 7, 8, 12, 27, 88
// Output-->7,45,8,12, 27, 88


#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexinsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[50] = {7, 8, 12, 27, 88};
    int size = 5;
    int element = 45;
    int index = 1;
    display(arr, size);
    indexinsertion(arr, size, element, 50, index);
    size += 1;
    display(arr, size);
    return 0;
}