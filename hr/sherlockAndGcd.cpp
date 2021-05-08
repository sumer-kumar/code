#include <bits/stdc++.h>
using namespace std;
#define ll long long

string sherlockAndGCD(int a[], int size);
//litrelly maja aa gya bhai


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//1 2 3
	int a[] = {2, 4};

	cout << sherlockAndGCD(a, 3) << endl;


	return 0;
}

string sherlockAndGCD(int a[], int size)
{

	int res = a[0];

	for (int i = 1; i < size - 1; i++) {
		res = __gcd(res, a[i]);
		if (res == 1)
			return "Yes";
	}

	return "No";
}