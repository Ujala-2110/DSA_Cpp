#include <bits/stdc++.h>
using namespace std;

string count_and_say(int n)
{
  if (n == 1)
    return "1";
  if (n == 2)
    return "11";                 // [n==1 & 2 -----> both are base cases]

  string s = "11";
  for (int i = 3; i <= n; i++)
  {
    string t = "";               // [t----> temporary string]
    s = s + "$";                 // [$(or any symbol) --->is a kind of delimeter to check the next element of last element]
    int c = 1;
    for (int j = 1; j < s.length(); j++)
    {
      if (s[j] != s[j - 1])
      {
        t = t + to_string(c);   // [to_string()----->To convert int into string (for c----->(as c is an integer))]
        t = t + s[j-1];
        c = 1;
      }
      else
        c++;
    }
    s = t;
  }
  return s;
}

int main()
{
  cout<<"Enter a number ";
  int n;
  cin >> n;
  cout << count_and_say(n);
  return 0;
}