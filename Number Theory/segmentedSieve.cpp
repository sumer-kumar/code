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


vector<ll> sieve(ll range)
{
	vector<bool> a(range+1,true);
	vector<ll> prime;
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
			prime.push_back(i);// cout<<i<<" "; 
	}
	return prime;
}



void segmentedSieve(ll a,ll b)
{
	vector<ll> prime = sieve(sqrt(b)+1);

	// for(ll x: prime)
	// 	cout<<x<<endl;

	vector<bool> isPrime(b-a+1,true);


	for(ll i=0;i<prime.size();i++)
	{
		ll start = (a/prime[i])*(prime[i]);
		if(start<a) start+=prime[i];

		for(ll j = start;j<=b;j+=prime[i])
		{
			isPrime[j-a] = false;
		}
	}

	for(ll i =0 ;i<=b-a;i++)
	{
		if(isPrime[i])
			cout<<(a+i)<<" ";
	}

}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll a,b;
    cin>>a>>b;
    segmentedSieve(a,b);
	return 0;
}