// Given a list arr of N integers, print sums of all subsets in it.

// Example 1:

// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5
// Explanation:
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then
// Sum = 2+3 = 5.

#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum, int arr[], int n, vector<int> &subset)
{
    if (ind == n)
    {
        subset.push_back(sum);
        return;
    }

    func(ind + 1, sum + arr[ind], arr, n, subset); // taking element

    func(ind + 1, sum, arr, n, subset); // without taking
}

int main()
{
    int arr[] = {5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> subset;
    func(0, 0, arr, n, subset);
    // sort(subset.begin(), subset.end());
    for(auto it:subset)
    cout<<it<<" ";
    return 0;
// Time complexity of this solution is O(2^n) and space complexity is O(2^n).
}


// Iterative C++ program to print sums of all
// possible subsets.
// #include <bits/stdc++.h>
// using namespace std;

// // Prints sums of all subsets of array
// void subsetSums(int arr[], int n)
// {
// 	// There are totoal 2^n subsets
// 	long long total = 1 << n;

// 	// Consider all numbers from 0 to 2^n - 1
// 	for (long long i = 0; i < total; i++) {
// 		long long sum = 0;

// 		// Consider binary representation of
// 		// current i to decide which elements
// 		// to pick.
// 		for (int j = 0; j < n; j++)
// 			if (i & (1 << j))
// 				sum += arr[j];

// 		// Print sum of picked elements.
// 		cout << sum << " ";
// 	}
// }

// // Driver code
// int main()
// {
// 	int arr[] = { 5, 4, 3 };
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	subsetSums(arr, n);
// 	return 0;
// }
