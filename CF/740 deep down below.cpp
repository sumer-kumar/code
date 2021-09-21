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

void solve()
{
		
	int n;
	cin>>n;

	vector<pair<int,pair<int,int>>> a;

	rep(i,0,n-1)
	{
		int size;
		cin>>size;

		int mx=0;

		rep(i,0,size-1)
		{
			int t;
			cin>>t;

			mx = max(mx,t-i);
		}
		a.pb({mx,{i,size}});
	}

	//sort
	sort(a.begin(),a.end());

	int curr = 0;
	int ans = 0;

	rep(i,0,n-1)
	{

		// cout<<a[i].se.fi<<" ";
		if(curr<=a[i].fi)
		{
			ans =ans+a[i].fi-curr+1;
			curr = a[i].fi+1;
		}
		curr += a[i].se.se;

		// cout<<curr<<" "<<ans<<endl;
	}

	cout<<ans<<endl;
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
    	solve();
    }


	return 0;
}

