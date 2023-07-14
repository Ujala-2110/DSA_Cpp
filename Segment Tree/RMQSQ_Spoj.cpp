#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int t[4 * MAXN];

void build(int a[], int si, int ss, int se)
{
    if (ss == se)
    {
        t[si] = a[ss];
    }
    else
    {
        int tm = (ss + se) / 2;
        build(a, si * 2, ss, tm);
        build(a, si * 2 + 1, tm + 1, se);
        t[si] = min(t[si * 2],t[si * 2 + 1]);
    }
}

int Min(int si, int ss, int se, int l, int r)
{
    if(ss > r || se < l) return 1e9;
    
    if(ss >= l && se <= r) return t[si];

    int mid = (ss + se) / 2;

    return min(Min(2*si,ss,mid,l,r) , Min(2*si+1,mid+1,se,l,r));
}

int main()
{
    int n;
    cin >> n;

    int arr[n+1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(arr, 1, 1, n);

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << Min(1, 1, n, l+1, r+1) << "\n";
    }

    return 0;
}