#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st = "GeeksQuiz";
    int l = st.length();

    stack<char> s;
    for (int i = 0; i < l; i++)
        s.push(st[i]);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}