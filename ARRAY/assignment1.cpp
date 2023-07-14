
// Selection sort

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int Minindex, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        Minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[Minindex])
            {
                Minindex = j;
            }
        }
        // Swap A[i] and A[Minindex]
        temp = A[i];
        A[i] = A[Minindex];
        A[Minindex] = temp;
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}