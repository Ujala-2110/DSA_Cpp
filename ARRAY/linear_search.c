# include<stdio.h>

int linearsearch(int arr[], int size, int element)
{
 for(int i=0;i<size;i++)
 {
  if(arr[i]==element)
  return i;
 }
 return -1;
}

int main()
{
 int arr[] ={1,3,5,56,64,73,123,225,444};
 int size = sizeof(arr)/sizeof(int);
 int element =1;
 int searchindex= linearsearch(arr, size, element);
 printf("The %d is present at %d",element,searchindex);
 return 0;
}