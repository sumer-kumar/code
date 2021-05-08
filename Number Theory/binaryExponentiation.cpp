#include <bits/stdc++.h>
using namespace std;
#define ll long long

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}


ll binexp(ll a,ll e)
{
	ll res = 1ll;
	while(e)
	{
		if(e&1)
		{
			res*=a;
		}
		a*=a;
		e>>=1;
	}
	return res;

} 

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll a,e;
    cin>>a>>e;
    cout<<binexp(a,e);

	return 0;
}