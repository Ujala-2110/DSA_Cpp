#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// Convert prefix to Infix expression
string preToInfix(string st)
{
    stack<string> s;

    int length = st.size();

    for (int i = 0; i < st.length(); i++)
    {
        if (isOperator(st[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op2 + st[i] + op1 + ")";
            s.push(temp);
        }
        else
        {
            s.push(string(1, st[i]));
        }
    }
    return s.top();
}

int main()
{
    string st = "ab*c+";
    cout << "Infix : " << preToInfix(st);
    return 0;
}
