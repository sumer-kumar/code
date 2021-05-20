#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int getUnits(vi a)
{
	int n = a.size();

	int buy=0;
	int sell=0;

	int count = 0;

	while(true)
	{
		// for(int x : a)
		// 	cout<<x<<" ";
		// cout<<endl;

		while(buy<n && a[buy]<=0)
			buy++;
		while(sell<n && a[sell]>=0)
			sell++;
		if(sell == n && buy == n)
			return count;

		// cout<<sell<<" "<<buy<<" "<<count<<"\n\n";

		if(a[buy] > abs(a[sell]))
		{
			a[buy] += a[sell];
			count += (abs(a[sell])*abs(sell-buy));
			a[sell] = 0;
		}
		else
		{
			a[sell] += a[buy];
			count += (a[buy]*abs(sell-buy));
			a[buy] = 0;
		}

	}

	return count;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	while(true)
	{
		cin>>n;
		if(n==0) return 0;

		vi a(n);

		int t;
		rep(i,0,n-1)
			cin>>a[i];

		cout<<getUnits(a)<<endl;
	}
	return 0;
}