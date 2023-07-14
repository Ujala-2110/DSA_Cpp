#include <stdio.h>

void bubblesort(int arr[], int n)
{
  int round, temp, flag;
  for (round = 1; round < n; round++)     // (n-1) round we have to go.
  {
    flag = 0;
    for (int i = 0; i <= n-1-round; i++)    // (n-1) comparison -> (n-2)comparison -> -> -> ----- ->(1)comparison.
      if (arr[i] > arr[i + 1])
      {
        flag = 1;
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    if (flag == 0)
    {
      printf("Round = %d\n", round);
      return;
    }
  }
}
int main()
{
  int arr[] = {0 ,23 ,14, 12 ,9 };
  int n = sizeof(arr) / sizeof(int);
  bubblesort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d\n", arr[i]);
  return 0;
}