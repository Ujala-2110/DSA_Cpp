#include <bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int main()
{
    stack<char> s;
    string st = "x+y*z/w+u";
    // string st = "(a-b)+c";
    reverse(st.begin(), st.end());
    for (int i = 0; i < st.length(); i++)
    {

        if (st[i] == '(')
        {
            st[i] = ')';
            i++;
        }
        else if (st[i] == ')')
        {
            st[i] = '(';
            i++;
        }
    }
    st = '(' + st + ')';

    int i = 0;
    string result = "";
    while (st[i] != '\0')
    {
        if (st[i] == '(')
            s.push(st[i]);

        else if (st[i] == '+' || st[i] == '*' || st[i] == '-' || st[i] == '/')
        {
            while (precedence(st[i]) < precedence(s.top()))
            {
                char c = s.top();
                result += c;

                s.pop();
            }
            s.push(st[i]);
        }
        else if (st[i] == '^')
        {
            while (precedence(st[i]) <= precedence(s.top()))
            {
                char c = s.top();
                result += c;

                s.pop();
            }
            s.push(st[i]);
        }
        else if (isalpha(st[i]) || isdigit(st[i]))
        {
            result += st[i];
        }
        else //( st[i] == ')' )
        {
            while (s.top() != '(')
            {
                char c = s.top();
                // q.push(c);
                result += c;
                s.pop();
            }
            s.pop();
        }
        i++;
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}