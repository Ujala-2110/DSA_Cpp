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
    // queue<char> q;
    // char st[50] = {'(', '(', 'a', '+', 'b', ')', '*', '(', 'c', '-', 'd', ')', ')'};
    string st = "(a+b)*(c-d)";
    // string st = "(a+(b*c-(d/e^f)*g)*h)";
    // string st = "(a+b*(c^d-e)^(f+g*h)-i)";
    // string st = "((a-b)+c)";
    // string st = "(((a+b)*c-(d-e))/(f+g))";

    string sk = "";
    st = sk + '(' + st + ')';
    int i = 0;
    string result = "";
    while (st[i] != '\0')
    {
        if (st[i] == '(')
            s.push(st[i]);

        else if (st[i] == '+' || st[i] == '*' || st[i] == '-' || st[i] == '/' || st[i] == '^')
        {
            while (precedence(st[i]) <= precedence(s.top()))
            {
                char c = s.top();
                result += c;
                // q.push(c);
                s.pop();
            }
            s.push(st[i]);
        }
        else if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= '0' && st[i] <= '9'))
        {
            result += st[i];
            // q.push(st[i]);
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
    // Pop all the remaining elements from the stack
    // while (!s.empty())
    // {
    //     result += s.top();
    //     s.pop();
    // }
    // while (!q.empty())
    // {
    //     cout << q.front();
    //     q.pop();
    // }

    cout << result;
    return 0;
}