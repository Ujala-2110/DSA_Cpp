#include <bits/stdc++.h>
using namespace std;

void findSymPairs(int arr[][2],int row)
{
    unordered_map<int,int>mp;

    for(int i=0;i<row;i++)
    {
        int fr = arr[i][0];
        int sc = arr[i][1];

        if(mp.find(sc) != mp.end() && mp[sc] == fr)
        cout<<sc<<" "<<fr<<"\n";

        else
        mp[fr] = sc;
    }
}

//Time Complexity of this solution is O(n) under the assumption that hash search and insert methods work in O(1) time.

int main()
{
    int arr[5][2];
    arr[0][0] = 11; arr[0][1] = 20;
    arr[1][0] = 30; arr[1][1] = 40;
    arr[2][0] = 5;  arr[2][1] = 10;
    arr[3][0] = 40;  arr[3][1] = 30;
    arr[4][0] = 10;  arr[4][1] = 5;
    findSymPairs(arr, 5);
    return 0;
}
