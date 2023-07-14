// A Gray code is a list of all 2n
//  bit strings of length n
// , where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

// Your task is to create a Gray code for a given length n

// Input
// The only input line has an integer n

// Output
// Print 2^n lines that describe the Gray code. You can print any valid solution.

// Constraints
// 1≤n≤16

// Example

// Input:
// 2

// Output:
// 00
// 01
// 11
// 10


#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
  if(n == 1){
    return {"0","1"};
  }

  vector<string>ans;
  vector<string>res = generate(n-1);

  for(int i=0;i<res.size();i++)
  {
    ans.push_back("0" + res[i]);
  }

  for(int i=res.size()-1;i>=0;i--)
  {
    ans.push_back("1" + res[i]);
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<string>graystring = generate(n);
  for(auto it : graystring)
  cout<<it<<"\n";

  //To take it in decimal
  vector<int>ans; // It will store all value in decimal form
  for(auto it : graystring)
  {
    ans.push_back(stoi(it,0,2)); //stoi(it,0,2) -> To conver binary string to decimal number
  }

  return 0;
}
