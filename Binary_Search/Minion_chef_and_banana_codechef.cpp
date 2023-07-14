#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool is_possible(ll arr[] , ll mid , ll h, ll n)
{
    ll hr = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] <= mid) hr++;
        else{
            hr += (arr[i] + (mid-1))/mid;
        }

        if(hr > h) return false;
    }

    return true;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, h;
        cin >> n >> h;

        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        ll mx = *max_element(arr,arr+n);
        ll lo = 1 , hi = mx;
        ll ans = -1;
        while(lo <= hi)
        {
            ll mid = (lo + hi)/2;

            if(is_possible(arr,mid,h,n)){
                ans = mid;
                hi = mid - 1;
            }

            else lo = mid + 1;
        }

        cout<<ans<<"\n";
    }

    return 0;
}