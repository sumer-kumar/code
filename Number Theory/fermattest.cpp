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
ll binexpmod(ll a,ll e,ll mod)
{
	ll res = 1ll;
	while(e)
	{
		if(e&1)
		{
			// res*=a;
			res = ((res%mod)*(a%mod))%mod;
		}
		a=((a%mod)*(a%mod))%mod;;
		e>>=1;
	}
	return res;
} 

bool fermetTest(ll prime, ll itr = 10)
{
	if(prime<=5)
		return (prime==5||prime==3||prime==2);

	srand(time(0));


	for(ll i=0;i<itr;i++)
	{
		int randm = 2 + rand()%(prime-3);

		if(binexpmod(randm,prime-1,prime)!=1)
			{
				cout<<randm<<" "<<(prime-1)<<" "<<prime<<" "<<binexpmod(randm,prime-1,prime)<<endl;			
				return false;
			}
	}
	return true;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll prime;
    cin>>prime;

    cout<<(fermetTest(prime)?"True":"False")<<endl;

	return 0;
}