#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll parent[100005];
ll sz[100005];

void make(int a){
    sz[a] = 1;
    parent[a] = a;
}

int find(int a){
    if(parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;

    if(sz[a]<sz[b]) swap(a,b);
        
    parent[b] = a;
    sz[a] += sz[b];
}
int main()
{
    int n, q, qu, a, b;
    cin>>n>>q;
    int size = n;
    for(int i=1;i<=n;i++){
        make(i);
    }
    
    while(q--){
        cin>>qu;
        if(qu==1){
            cin>>a>>b;
            if(find(a)!=find(b)) size--;
            Union(a,b);
        }
        else if(qu==2){
            cin>>a>>b;
            string res = (find(a)==find(b))?"YES":"NO";
            cout<<res<<" ";
        }
        else{
            cout<<size<<" ";
        }
    }
    return 0;
}