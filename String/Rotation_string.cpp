#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    str1 = "ABACD";
    str2 = "CDABA";
    if (str1.length() != str2.length())
        cout << "No";
    else
    {
        string temp = str1 + str1;
        if (temp.find(str2) != string::npos)  //string::npos -->It actually means until the end of the string.
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}