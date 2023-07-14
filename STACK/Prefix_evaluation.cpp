#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    // string st ="+ 9 * 2 6";
    string st = "+ 9 * 12 6";
    // while (st[i] != '\0')
    for (int i = st.length() - 1; i >= 0; i--)
    {
        // if (st[i] >= '0' && st[i] <= '9')
        // {
        //     s.push(st[i] - '0');
        // }
        if (isdigit(st[i]))
        {
            // there may be more than
            // one digits in a number
            int num = 0, j = i;
            while (i < st.size() && isdigit(st[i]))
                i--;
            i++;

            // from [i, j] exprsn contains a number
            for (int k = i; k <= j; k++)
                num = num * 10 + int(st[k] - '0');

            //push the element in the stack
            s.push(num);
        }
        else if (st[i] == ' ')
            continue;

        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            switch (st[i])
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            }
        }
        // i++;
    }
    cout << s.top();
    return 0;
}