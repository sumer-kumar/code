#include <bits/stdc++.h>
using namespace std;
#define ll long long



#define max 200



long long fight(long long a[], long long size) {
	long long count = 0;

	for (long long i = 1; i < size; i++) {
		if (a[i - 1] > a[i])
		{
			a[i - 1]++;
			count++;
		}

		else if (a[i - 1] < a[i])
		{
			a[i]++;
			count++;
		}
	}

	return count;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long test;
	cin >> test;
	long long a[max];

	while (test--) {
		long long size;
		cin >> size;

		for (long long i = 0; i < size; i++) {
			cin >> a[i];
		}

		cout << fight(a, size) << endl;

	}

	return 0;
}