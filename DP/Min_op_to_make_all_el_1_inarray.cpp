#include <bits/stdc++.h>
using namespace std;


bool CheckAllEqual(int arr[], int N)
{
	for (int i = 1; i < N; i++) {

		// If all array elements are not equal
		if (arr[0] != arr[i]) {

			return false;
		}
	}

	return true;
}

int minCntOperations(int arr[], int N)
{

	int Max = *max_element(arr, arr + N);

	// Check if a number is a power of 2 or not
	bool isPower2 = !(Max && (Max & (Max - 1))); //initial max is for (max = 0) case

	// If Max is a power of 2 and all array elements are equal
	if (isPower2 && CheckAllEqual(arr, N)) {

		return log2(Max); 
	}
	else {

		return ceil(log2(Max)) + 1;
	}
}

int main()
{
    int arr[] = {2,2,2,5} ;
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << minCntOperations(arr, N);
}


