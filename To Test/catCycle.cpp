#include <bits/stdc++.h>
using namespace std;
#define ll long long




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll test;
	cin >> test;
	ll size;
	ll k;
	ll a, b;
	while (test--) {
		cin >> size >> k;

		a = size;
		b = 1;

		for (ll i = 0; i < k; i++) {

			if (b + 1 > size)
				b = 1;
			else
				b++;

			if (a - 1 <= 0)
				a = size;
			else
				a--;

			if (a == b)
			{
				if (b + 1 > size)
					b = 1;
				else
					b++;
			}

		}
		cout << b << endl;
	}
	return 0;
}
