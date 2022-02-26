#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef priority_queue<int> pq_d;
typedef priority_queue<int,vector<int>,greater<int>> pq_a;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

ll sum(ll x)
{
	return (1ll*(x+1)*x)/2;
}

ll solve(vi &t,vi &h)
{
	int size = t.size();
	vector<pii> a(size);

	rep(i,0,size-1)
	{
		int r=t[i];
		int l = t[i]-h[i]+1;
		a[i].fi=l;
		a[i].se=r;
	}

	sort(a.begin(),a.end());

	ll res=0;
	int l=1,r=0;

	for(auto x : a)
	{
		int cl = x.fi;
		int cr = x.se;
		if(cl>r)
		{
			res += sum(r-l+1);
			r=cr;
			l=cl;
		}
		else
		{
			r=max(r,cr);
		}
	}
	res += sum(r-l+1);

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;
    	vi t(n),h(n);
    	rep(i,0,n-1) cin>>t[i];
    	rep(i,0,n-1) cin>>h[i];
    	cout<<solve(t,h)<<endl;
    }


	return 0;
}

