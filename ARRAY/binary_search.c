#include <stdio.h>
int binarysearch(int arr[], int size, int element)
{
  int low = 0;
  int high = size - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == element)
      return mid;

    if (arr[mid] < element)
      low = mid + 1;

    else
      high = mid - 1;
  }
  return -1;
}

int main()
{ // For binary search sorted array is a must condition.
  int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
  int size = sizeof(arr) / sizeof(int);
  int element = 123;
  int searchindex = binarysearch(arr, size, element);
  printf("The %d is present at %d", element, searchindex);
  return 0;
}