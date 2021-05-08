#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll amitshah(ll a[], ll size, ll k, ll constant)
{
	ll maxh = INT_MIN;
	ll curr = k;
	sort(a, a + size);
	for (ll i = 1; i < size; i++)
	{
		if (a[i] - a[i - 1] <= constant)
		{
			curr += k;
			maxh = max(maxh, curr);
		}
		else
		{
			maxh = max(maxh, curr);
			curr = k;
		}
	}
	return maxh;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll constant;
	cin >> constant;

	cout << amitshah(a, n, k, constant);
	return 0;
}