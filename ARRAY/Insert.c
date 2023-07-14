#include <stdio.h>

void Insertion(int arr[], int size, int index, int element)
{
    if (index > size - 1)
        return;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i] = arr[i + 1];
    }
    arr[index] = element;
}

int main()
{
    int arr[50] = {1, 2, 5, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    int index = 3;
    int element = 10;
    Insertion(arr, n, index, element);
    n += 1;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}