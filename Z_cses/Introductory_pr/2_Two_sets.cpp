// Your task is to divide the numbers 1,2,…,n
//  into two sets of equal sum.

// Input

// The only input line contains an integer n
// .

// Output

// Print "YES", if the division is possible, and "NO" otherwise.

// After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

// Constraints
// 1≤n≤106

// Example 1

// Input:
// 7

// Output:
// YES
// 4
// 1 2 4 7
// 3
// 3 5 6

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define loop for (int i = 0; i < n; i++)
#define loop1 for (int i = 1; i <= n; i++)
#define asort(arr, n) sort(arr, arr + n)
#define dsort(arr, n) sort(arr, arr + n, greater<>())
#define vasort(v) sort(v.begin(), v.end());
#define vdsort(v) sort(v.begin(), v.end(), greater<>());

// Mine
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;

  ll x = (n * (n + 1)) / 2;

  if (n == 3)
  {
    cout << "YES\n";
    cout << 1 << "\n";
    cout << 3 << "\n";
    cout << 2 << "\n";
    cout << 1 << " " << 2 << "\n";
  }

  else if (x & 1)
    cout << "NO\n";
  else
  {
    ll hf = x / 2;
    ll i = 1, j = n;

    vector<int> ans;
    ans.push_back(1);
    ans.push_back(n);
    ll sum = n + 1;
    j--;
    i++;
    while (i < j)
    {
      if (sum == hf)
        break;

      if ((sum + j) <= hf)
      {
        sum += j;
        ans.push_back(j);
        j--;
      }

      if ((sum + i) <= hf)
      {
        sum += i;
        ans.push_back(i);
        i++;
      }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto it : ans)
      cout << it << " ";
    cout << "\n";
    cout << (j - i + 1) << "\n";
    for (int k = i; k <= j; k++)
      cout << k << " ";
    cout << "\n";
  }
  return 0;
}

// Short of mine
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n ; cin >> n;
  ll res = n*(n+1)/2;
  if (res % 2) cout << "NO";
  else {
    cout << "YES\n";
    vector <int> x,y;
    ll ans = res/2;
    // cout << ans << endl;
    for (int i=n;i>0;i--) {
        if (ans >= i) {x.push_back(i);ans -= i;}
        else y.push_back(i);
    }
    int a = x.size();
    cout << a << endl;
    for (int i = 0; i < a;i++) cout << x[i] << " " ;
    cout << endl;
    int b = y.size();
    cout << b << endl;
    for (int i = 0; i < b;i++) cout << y[i] << " " ;
  }
}


// Standard algo
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // ll t;
  // cin >> t;

  // // for (int tt = 1; tt <= t; tt++)
  // while (t--)
  // {

  // }

  ll n;
  cin >> n;
  ll sum = (n * (n + 1)) / 2;
  if (sum % 2)
  {
    cout << "NO" << endl;
    return 0;
  }
  vector<ll> v1, v2;
  ll j;
  if (n % 4)
    j = 3;
  else
    j = 4;
  for (ll i = 0; i < (n - 1) / 4; i++)
  {
    v1.push_back(4 * i + 1 + j);
    v1.push_back(4 * i + 4 + j);
    v2.push_back(4 * i + 2 + j);
    v2.push_back(4 * i + 3 + j);
  }
  if (n % 4)
  {
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
  }
  else
  {
    v1.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v1.push_back(4);
  }
  cout << "YES" << endl;
  cout << v1.size() << endl;
  for (auto i : v1)
    cout << i << " ";
  cout << endl;
  cout << v2.size() << endl;
  for (auto i : v2)
    cout << i << " ";

  return 0;
}