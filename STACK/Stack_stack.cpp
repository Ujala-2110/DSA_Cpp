#include <iostream>
using namespace std;
const int n = 10;
int stack1[n];
int stack2[n];
int top1 = -1;
int top2 = -1;
int ct=0;
void push(int data)
{
    if (top1 == n - 1)
        return;
    top1++;
    stack1[top1] = data;
   ct++;
}
void pop()
{
    if (top1 == -1)
        return;

    top1--;
}
void printsecond()
{   top1 = ct-1;
    while(top1 !=-1){
    stack2[top2]=stack1[top1];
    pop();
    cout<<stack2[top2]<<" ";
    }

}
int main()
{
    push(10);
    push(30);
    push(20);
    push(50);
    push(90);
    push(20);
    printsecond();
    return 0;
}