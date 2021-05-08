#include <bits/stdc++.h>
using namespace std;
#define ll long long

int power(int a, int n);
int closestNumber(int a, int b, int x);


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, x;
	cin >> a >> b >> x;

	cout << closestNumber(a, b, x) << endl;


	return 0;
}
//fast exponentiation
//a^n
int power(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2 == 0) //if power is even
		{	a *= a;
			n /= 2;
		}

		else
		{
			res *= a;
			n--;
		}
	}

	return res;
}

int closestNumber(int a, int b, int x)
{
	int res = power(a, b);


	return x * (res / x);
}











