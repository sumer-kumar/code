#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll fastExp(ll base, ll endifxp);
ll fastExpMod(ll base, ll exp, ll mod);

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll base, power, mod;
	cin >> base >> power >> mod;
	cout << fastExpMod(base, power, mod);

	return 0;
}

ll fastExp(ll base, ll exp)
{
	ll res = 1;
	while (exp > 0)
	{
		if (exp & 1ll)
			res = base * res;
		exp = exp >> 1;
		base = base * base;
	}
	return res;
}
ll fastExpMod(ll base, ll exp, ll mod)
{
	ll res = 1;
	while (exp > 0)
	{
		if (exp & 1ll)
			res = ((base % mod) * (res % mod)) % mod;
		exp = exp >> 1;
		base = ((base % mod) * (base % mod)) % mod;
	}
	return res;
}