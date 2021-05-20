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
typedef vector<bool> vb;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int getMaxDeff(vb a,int size)
{
	int curr = 0;
	int maxDef = INT_MIN;
	for(int i=0;i<=size+1;i++)
	{
		if(a[i]==true)
		{
			maxDef = max(maxDef,i-curr-1);
			curr = i;
		}
	}

	return maxDef;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;

	int w,h,n;
	int x,y;
	while(t--)
	{
		cin>>w>>h>>n;
		vb wf(w+2,false);
		vb ht(h+2,false);
		wf[w+1] = true;
		ht[h+1] = true;

		rep(i,0,n-1)
		{
			cin>>x>>y;
			wf[x] = true;
			ht[y] = true;
		}

		int maxw = getMaxDeff(wf,w);
		int maxh = getMaxDeff(ht,h);
 		cout<<(maxh*maxw);
	}	

	return 0;
}