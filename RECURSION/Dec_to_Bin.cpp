#include<bits/stdc++.h>
using namespace std;

void DtoB(int n)
{
    if(n==1)
    {
        cout<<n;
        return;
    }

    else{
        DtoB(n/2);
        cout<<n%2;
    }
    
}

int main()
{
    DtoB(8);
    return 0;
}
