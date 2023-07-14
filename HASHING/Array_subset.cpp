#include <bits/stdc++.h>
using namespace std;
int hsh[1001];

bool isSubset(int arr1[], int arr2[], int m, int n)
{
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    for (int i = 0; i < n; i++)
    {
        if (!binary_search(arr1, arr1 + m, arr2[i]))
            return false;
    }
    return true;
}

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");
    return 0;
    
}

//Using set
//Set takes only unique elements
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	// code
// 	int arr1[] = { 11, 1, 13, 21, 3, 7 };
// 	int arr2[] = { 11, 3, 7, 1 };
// 	int m = sizeof(arr1) / sizeof(arr1[0]);
// 	int n = sizeof(arr2) / sizeof(arr2[0]);

// 	unordered_set<int> s;
// 	for (int i = 0; i < m; i++) {
// 		s.insert(arr1[i]);
// 	}
// 	int p = s.size();
// 	for (int i = 0; i < n; i++) {
// 		s.insert(arr2[i]);
// 	}
// 	if (s.size() == p) {
// 	cout << "arr2[] is subset of arr1[] "<< "\n";
// 	}
// 	else {
// 		cout << "arr2[] is not subset of arr1[] "<< "\n";
// 	}
// 	return 0;
// }
