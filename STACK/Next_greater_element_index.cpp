#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define loop for (int i = 0; i < n; i++)
// #define out cout << "Case"<< " "<< "#" << tt << ": "

void ngi(int n, int b[], vector<int> &arr)
{
  stack<int> s;
  for (int i = n - 1; i >= 0; i--)
  {
    if (!s.empty())
    {
      while (!s.empty() && b[s.top()] <= b[i])
      {
        s.pop();
      }
    }
    arr[i] = s.empty() ? n : s.top();
    s.push(i);
  }
}

int main()
{
    int n = 13;
    int b[] = {5, 3, 1, 5, 3, 2, 2, 5, 8, 5, 1, 1, 5};
    vector<int>arr(n,0);
    ngi(n,b,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}