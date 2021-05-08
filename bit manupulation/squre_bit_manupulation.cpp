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

int square(int n)
{
	n = abs(n);
	int order = 0;
	int res = 0;
	int x = n;

	while(x)
	{
		if(x&1) //if lsb is one
		{
			res += n<<order;
		}	

		x = x>>1;
		order++;
	}

	return res;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	cout<<square(n)<<endl;

	return 0;
}