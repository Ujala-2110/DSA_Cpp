#include <bits/stdc++.h>
using namespace std;

//Method->1
// bool areDisjoint(int set1[], int set2[], int n, int m)
// {
//     unordered_map<int, int> ump;
//     for (int i = 0; i < n; i++)
//     {
//         ump[set1[i]] = 1;
//     }
//     for (int i = 0; i < m; i++)
//     {
//         if (ump[set2[i]] == 1)
//             return false;
//     }

//     return true;
// }

//Method->2
// bool areDisjoint(int set1[], int set2[], int n1, int n2)
// {
//     // Creates an empty hashset
//     set<int> myset;

//     // Traverse the first set and store its elements in hash
//     for (int i = 0; i < n1; i++)
//         myset.insert(set1[i]);

//     // Traverse the second set and check if any element of it
//     // is already in hash or not.
//     for (int i = 0; i < n2; i++)
//         if (myset.find(set2[i]) != myset.end())
//             return false;

//     return true;
// }

// Method->3 (Use Sorting and Merging) 
// 1) Sort first and second sets. 
// 2) Use merge like the process to compare elements

bool areDisjoint(int set1[], int set2[], int n, int m)
{
    sort(set1, set1 + n);
    sort(set2, set2 + m);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (set1[i] < set2[j])
            i++;
        else if (set1[i] > set2[j])
            j++;
        else //set1[i]==set2[j]
            return false;
    }
    return true;
}

int main()
{
    int set1[] = {12, 34, 11, 9, 3};
    int set2[] = {4, 2, 1, 5};
    int n = sizeof(set1) / sizeof(set1[0]);
    int m = sizeof(set2) / sizeof(set2[0]);
    areDisjoint(set1, set2, n, m) ? cout << "Yes" : cout << " No";
    return 0;
}