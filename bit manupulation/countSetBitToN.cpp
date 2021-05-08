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

int countSetBitToN(int n)
{
	n++;
	int cnt = n/2;
	int powerf2 = 2;


	while(powerf2<=n)
	{
		
		int totalPairs = n/powerf2;

		cnt += (totalPairs/2)*powerf2;

		cnt += (totalPairs&1)?n%powerf2:0;

		powerf2<<=1;
		
	}
	return cnt;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	cout<<countSetBitToN(n);

	return 0;
}