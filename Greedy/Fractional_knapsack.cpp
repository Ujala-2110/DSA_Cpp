#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

static bool mycomp(Item a, Item b)
{
    return (double)a.value / (double)a.weight > (double)b.value / (double)b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, mycomp); //sorted according to (value/weight)
    // for(int i=0;i<n;i++) cout<<arr[i].value<<" "<<arr[i].weight<<"\n";

    double val = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (W >= arr[i].weight)
        {
            val += arr[i].value;
            W -= arr[i].weight;
        }

        else
        {
            val += W * ((arr[i].value / (double)arr[i].weight));
            break;
        }
    }

    return val;
}

int main()
{
    int n, W;
    cin >> n >> W;

    Item arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << fractionalKnapsack(W,arr,n);
    return 0;
}