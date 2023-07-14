#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    s1 = "xy";
    int l1 = s1.length();
    s2 = "12";
    int l2 = s2.length();
    s3 = "x1y2";
    int l3 = s3.length();
    int flag = 0;

    if ((l1 + l2) != l3)
        flag = 1;
    else{
    int i=0,j=0,k=0;
    while(k<l3)
    {
      if(i<l1 && s1[i]==s3[k]) i++;
      else if(j<l2 && s2[j]==s3[k]) j++;
      else{
          flag=1;
          break;
      }
    k++;
    }
  } 
    if (flag == 1)
        cout << "no\n";
    else
        cout << "yes\n";
    return 0;
}