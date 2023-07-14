#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    // string st = "2 3 1* + 9 -";
    string st = "100 200 + 2 / 5 * 7 +";
    // while (st[i] != '\0')
    for (int i = 0; i < st.length(); i++)
    {
        // if (st[i] >= '0' && st[i] <= '9')
        // {
        //     s.push(st[i] - '0');
        // }
        if (isdigit(st[i]))
        {
            int num = 0;

            //extract full number
            while (isdigit(st[i]))
            {
                num = num * 10 + (int)(st[i] - '0');
                i++;
            }
            //Before condition become false (i++) will take an extra character
            i--;

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
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            }
        }
        // i++;
    }
    cout << s.top();
    return 0;
}