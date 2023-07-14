#include <bits/stdc++.h>
using namespace std;

//-> Z Algorithm ->(For Pattern matching  || No. of distinct substring in string || String compression)
vector<int> z_function(string s)
{
  int n = (int)s.length();
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; ++i)
  {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
  // It will return z array
}

// It will return hash value of string
long long compute_hash(string const &s)
{
  const int p = 31;
  const int m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s)
  {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

// Search for duplicate strings in an array of strings

vector<vector<int>> group_identical_strings(vector<string> const& s) {
  int n = s.size();
  vector<pair<long long, int>> hashes(n);
  for (int i = 0; i < n; i++)
    hashes[i] = {compute_hash(s[i]), i};

  sort(hashes.begin(), hashes.end());

  vector<vector<int>> groups;
  for (int i = 0; i < n; i++) {
    if (i == 0 || hashes[i].first != hashes[i-1].first)
    groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }
  return groups;
}

// The prefix function for this string is defined as an array pi of length n, where pi[i]  is the length of the longest proper prefix
// of the substring s(0---i) which is also a suffix of this substring. A proper prefix of a string is a prefix that is not equal to
// the string itself. By definition,pi[0] =0

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}


