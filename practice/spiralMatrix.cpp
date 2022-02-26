#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> spiralMat(int a[][6], int r, int c);

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[][6] = { { 1, 2, 3, 4, 5, 6 },
		{ 7, 8, 9, 10, 11, 12 },
		{ 13, 14, 15, 16, 17, 18 }
	};
	vector<int> v = spiralMat(a, 3, 6);
	for (auto x : v)
		cout << " " << x;

	return 0;
}

vector<int> spiralMat(int a[][6], int r, int c) {
	vector<int> v;
	//ho jae bhai
	//darr lagg raha hai

	int ru = 0;
	int rl = r - 1;

	int cr = c - 1;
	int cl = 0;

	while (ru <= rl && cl <= cr) {

		for (int i = cl; i <= cr; i++)
			v.push_back(a[ru][i]);
		ru++;

		for (int i = ru; i <= rl; i++)
			v.push_back(a[i][cr]);
		cr--;

		if (ru < rl) {
			for (int i = cr; i >= cl; i--)
				v.push_back(a[rl][i]);
			rl--;
		}
		if (cl < cr) {
			for (int i = rl; i >= ru; i--)
				v.push_back(a[i][cl]);
			cl++;
		}

	}
	return v;
}
