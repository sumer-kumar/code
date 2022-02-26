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

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):1;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}