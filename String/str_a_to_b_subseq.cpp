// Given two strings A and B, the task is to count the minimum number of operations required to convert the string A to B. In one operation, select a subsequence from string A and convert every character of that subsequence to the smallest character present in it. If it is not possible to transform, then print “-1”.

#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum number
// of operation
void transformString(string str1, string str2)
{
	// Storing data
	int N = str1.length();

	vector<int> convChar[26];
	vector<int> str1array[26];

	// Initialize both arrays
	for (int i = 0; i < 26; i++) {
		vector<int> v;
		convChar[i] = v;
		str1array[i] = v;
	}

	// Stores the index of character
	map<int, char> convertMap;

	// Filling str1array, convChar
	// and hashmap convertMap.
	for (int i = 0; i < N; i++) {
		str1array[str1[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < N; i++) {

		// Not possible to convert
		if (str1[i] < str2[i]) {
			cout << -1 << endl;
			return;
		}
		else if (str1[i] == str2[i]) continue;
		else {
			convChar[str2[i] - 'a'].push_back(i);
			convertMap[i] = str2[i];
		}
	}

	// Calculate result
	// Initializing return values
	int ret = 0;
	vector<vector<int> > retv;

	// Iterating the character from
	// the end
	for (int i = 25; i >= 0; i--) {

		vector<int> v = convChar[i];

		if (v.size() == 0)
			continue;

		// Increment the number of
		// operations
		ret++;
		vector<int> v1 = str1array[i];

		// Not possible to convert
		if (v1.size() == 0) {
			cout << -1 << endl;
			return;
		}

		// to check whether the final
		// element has been added
		// in set S or not.
		bool isScompleted = false;

		for (int j = 0; j < v1.size(); j++) {

			// Check if v1[j] is present
			// in hashmap or not
			if (convertMap.find(v1[j])
				!= convertMap.end()) {

				char a = convertMap[v1[j]];

				// Already converted then
				// then continue
				if (a > i + 'a')
					continue;
				else {
					v.push_back(v1[j]);
					isScompleted = true;
					retv.push_back(v);
					break;
				}
			}
			else {
				v.push_back(v1[j]);
				isScompleted = true;
				retv.push_back(v);
				break;
			}
		}

		// Not possible to convert
		if (!isScompleted) {
			cout << -1 << endl;
			return;
		}
	}

	// Print the result
	cout << ret << endl;
}

// Driver Code
int main()
{
	// Given strings
	string A = "abcab";
	string B = "aabab";

	// Function Call
	transformString(A, B);
	return 0;
}
