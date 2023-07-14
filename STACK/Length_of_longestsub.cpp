#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
	int n = str.length();

	stack<int> stk;
	stk.push(-1);

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			stk.push(i);
		
		// If closing bracket, i.e.,str[i] = ')'
		else
		{
			// Pop the previous opening
			// bracket's index
			if (!stk.empty())
			{
				stk.pop();
			}
			
			// Check if this length formed with base of
			// current valid substring is more than max
			// so far
			if (!stk.empty())
				result = max(result, i - stk.top());

			// If stack is empty. push current index as
			// base for next valid substring (if any)
			else
				stk.push(i);
		}
	}

	return result;
}

int main()
{
	string str = "((()()";

	cout << findMaxLen(str) << endl;

	str = "()(()))))";

	cout << findMaxLen(str) << endl;

	return 0;
}
