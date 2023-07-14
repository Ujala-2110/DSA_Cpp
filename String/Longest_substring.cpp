#include <bits/stdc++.h>
using namespace std;

void palstring(string s, int n)
{
   int l, h;
   int start = 0, end = 1;
   for (int i = 1; i < n; i++)
   {
      //Even Substring
      l = i - 1;
      h = i;
      while (l >= 0 && h < n && s[l] == s[h])
      {
         if (h - l + 1 > end)
         {
            start = l;
            end = h - l + 1;
         }
         l--;
         h++;
      }
      //Odd Substring
      l = i - 1;
      h = i + 1;
      while (l >= 0 && h < n && s[l] == s[h])
      {
         if (h - l + 1 > end)
         {
            start = l;
            end = h - l + 1;
         }
         l--;
         h++;
      }
   }
   for (int i = start; i <= start + end - 1; i++)
      cout << s[i];
}

int main()
{
   string str = "Geeks";
   int n = str.length();
   palstring(str, n);
   return 0;
}