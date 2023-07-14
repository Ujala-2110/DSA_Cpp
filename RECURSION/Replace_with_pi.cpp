#include <bits/stdc++.h>
using namespace std;

void Replace_pi(string str)
{
    if (str.size() == 0)
    {
        return;
    }
    if (str[0] == 'p' && str[1] == 'i')
    {
        cout << "3.14";
        Replace_pi(str.substr(2));
    }

    else
    {
        cout << str[0];
        Replace_pi(str.substr(1));
    }
}

int main()
{
    string a = "pippxxppiixipi";
    Replace_pi(a);
    return 0;
}
