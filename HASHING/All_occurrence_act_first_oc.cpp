#include<bits/stdc++.h>
using namespace std;

void groupElements(int arr[],int n)
{
    unordered_map<int,int>mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
       while(mp[arr[i]])
       {
           cout<<arr[i]<<" ";
           mp[arr[i]]--;
       }
    }
    
    
}

int main()
{
    int arr[] = {5, 3, 5, 1, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    groupElements(arr, n);
    return 0;
}