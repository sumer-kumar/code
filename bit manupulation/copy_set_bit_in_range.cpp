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

int copySetBit(int x,int y,int l,int r)
{
	int mask = 1;
	mask = mask<<(r-l+1);
	mask--;
	mask = mask<<(l-1);
	// bitset<10> bitx(mask);
	y = y&mask;

	x = x|y;

	return x;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,l,r;
    
    cin>>x>>y>>l>>r;
    cout<<copySetBit(x,y,l,r);

	return 0;
}