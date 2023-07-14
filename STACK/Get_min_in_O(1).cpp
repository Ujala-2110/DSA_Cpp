// You are given N elements and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

#include<bits/stdc++.h>
using namespace std;

int minEle;
stack<int> s;

/*returns min element from stack*/
int getMin()
{

    if (s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int pop()
{

    if (s.empty())
        return -1;

    int x = s.top();
    s.pop();

    if (x >= minEle)
        return x;

    else
    {
        int currele = minEle;
        minEle = 2 * minEle - x;
        return currele;
    }
}

/*push element x into the stack*/
void push(int x)
{

    if (s.empty())
    {
        s.push(x);
        minEle = x;
    }

    else if (x < minEle)
    {
        int currele = x;
        x = 2 * x - minEle;
        s.push(x);
        minEle = currele;
    }

    else
    {
        s.push(x);
    }
}