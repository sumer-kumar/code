#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll amitshah(ll a[],ll size,ll k,ll constant)
{
    ll maxh = INT_MIN;
    ll curr = k;
    sort(a,a+size);
    for(ll i = 1;i<size;i++)
    {
        if(a[i]-a[i-1]<=constant)
        {
            curr+=k;
            maxh = max(maxh,curr);
        }
        else
        {
            maxh = max(maxh,curr);
            curr = k;
        }
    }
    return maxh;
}


int main(){
    ll a[] = { 16, 26, 5, 7, 19, 24, 22 };

    cout<<amitshah(a,7,4,3);

     return 0;
}