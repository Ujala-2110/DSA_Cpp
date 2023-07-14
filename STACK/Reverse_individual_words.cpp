#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;

    string st = "Geeks for Geeks";
    int l = st.length();
    for (int i = 0; i < l; i++)
    {
        if (st[i] != ' ')
            s.push(st[i]);

        else
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}