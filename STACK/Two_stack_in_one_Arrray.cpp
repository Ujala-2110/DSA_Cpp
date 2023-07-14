#include <bits/stdc++.h>
using namespace std;
const int n = 16;

class twoStacks
{
    int top1, top2;

public:
    twoStacks()
    {
        top1 = -1;
        top2 = n;
    }
    int arr[n];
    void push1(int data)
    {
        
        // There is at least one empty space for new element
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
            return;
    }
    void push2(int data)
    {
        // There is at least one empty space for new element
        if (top2 > top1 + 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
            return;
    }
    int pop1()
    {
        if (top1 == -1)
            return -1;
        int x = arr[top1];
        top1--;
        return x;
    }
    int pop2()
    {
        if (top2 == n)
            return -1;
        int x = arr[top2];
        top2++;
        return x;
    }
};

int main()
{
    twoStacks ts;
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push1(18);
    ts.push2(7);
    ts.push2(8);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    ts.push2(66);
    ts.push2(66);
    ts.push2(66);
    ts.push2(65);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}