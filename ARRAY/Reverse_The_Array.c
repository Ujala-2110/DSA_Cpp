#include <stdio.h>
int main()
{
    int n, arr[n];
    printf("Enter a number :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[n - i - 1]);
    }
    return 0;
}