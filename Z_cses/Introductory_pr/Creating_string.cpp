// Given a string, your task is to generate all different strings that can be created using its characters.

// Input

// The only input line has a string of length n
// . Each character is between a–z.

// Output

// First print an integer k
// : the number of strings. Then print k
//  lines: the strings in alphabetical order.

// Constraints
// 1≤n≤8

// Example

// Input:
// aabac

// Output:
// 20
// aaabc
// aaacb
// aabac
// aabca
// aacab
// aacba
// abaac
// abaca
// abcaa
// acaab
// acaba
// acbaa
// baaac
// baaca
// bacaa
// bcaaa
// caaab
// caaba
// cabaa
// cbaaa

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  sort(s.begin(),s.end());
  vector<string>ans;

  //O(n*n!) n<=8
  do{
    ans.push_back(s);
  } while(next_permutation(s.begin(),s.end()));

  cout<<ans.size()<<"\n";
  for(auto it : ans) cout<<it<<"\n";

  return 0;
}
