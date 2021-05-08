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

void sieve(ll range)
{
	vector<bool> a(range+1,true);
	for(ll i=2;i<=range;i++)
	{
		if(a[i])
		{
			for(ll j=i*i;j<=range;j+=i)
			{
				a[j] = false;
			}
		}
	}

	for(ll i=2;i<=range;i++)
	{
		if(a[i])
			cout<<i<<" ";
	}
}



int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll range;
    cin>>range;
    sieve(range);
	return 0;
}