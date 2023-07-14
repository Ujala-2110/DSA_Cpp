#include <bits/stdc++.h>
using namespace std;

int Min(int arr[], int N)
{
    int min_ele = arr[0];
    int min_ind = 0;
    for (int i = 1; i < N; i++)
    {
        if (min_ele > arr[i])
        {
            min_ele = arr[i];
            min_ind = i;
        }
    }

    return min_ind;
}

int maximizeMin(int arr[], int N, int S, int M)
{
    for (int i = 0; i < M; i++)
    {
        int ind = Min(arr, N);

        //increament the minimum element
        arr[ind]++;

        int left = ind-1;
        int right = ind+1;

        for(int j = 0; j < S-1; j++)
        {
            if(left == -1) arr[right++]++;

            else if(right == N) arr[left--]++;

            else{
                if(arr[left] < arr[right]) arr[left--]++;
                else arr[right++]++;
            }
        }
    }

    int index = Min(arr,N);
    return arr[index];

}

int main()
{
    int arr[] = {1, 7, 2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int S = 2, M = 3;

    cout << maximizeMin(arr, N, S, M);

    return 0;
}