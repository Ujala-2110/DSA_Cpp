#include <stdio.h>

int maximum_in_array(int arr[],int size)
{
 int max=arr[0];

 for(int i=0;i<size;i++)
  if(arr[i]>max)
    max = arr[i];

return max;
}
int minimum_in_array(int arr[],int size)
{
 int min=arr[0];
 for(int i=0;i<size;i++)
  if(arr[i]<min)
    min=arr[i];

return min;
}

int main()
{
int arr[] = {1000, 11, 445, 1, 330, 3000};
int n = sizeof(arr) / sizeof(int);
int maximum=maximum_in_array(arr,n);
printf("maximum value of array is %d\n",maximum);
int minimum=minimum_in_array(arr,n);
printf("minimum value of array is %d",minimum);
return 0;
}