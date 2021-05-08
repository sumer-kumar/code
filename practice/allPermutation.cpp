#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void permute(string a, int l, int r);
int main()

{
	string str;
	cin >> str;
	permute(str, 0, str.length() - 1);
	return 0;
}
//using backtracking
void permute(string a, int l, int r)
{
	// Base case
	if (l == r)
		cout << a << endl;
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{
			// Swapping done
			swap(a[l], a[i]);
			// Recursion called
			permute(a, l + 1, r);
			//backtrack
			swap(a[l], a[i]);
		}
	}
}