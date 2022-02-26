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


bool cmp(pii &a,pii &b)
{
	if(a.fi!=b.fi)
		return a.fi<b.fi;

	return a.se>b.se;
}

void solve(vector<pii> &a)
{
	int size = a.size();

	sort(a.begin(),a.end(),cmp);

	if(a[0].fi==a[0].se)
		cout<<a[0].fi<<" "<<a[0].se<<" "<<a[0].fi<<endl;

	rep(i,1,size-1)
	{
		if(a[i].fi == a[i-1].fi)
		{
			cout<<a[i-1].fi<<" "<<a[i-1].se<<" "<<(a[i].se+1)<<endl;
		}
		else if(a[i].se==a[i-1].se)
		{
			cout<<a[i-1].fi<<" "<<a[i].se<<" "<<(a[i].fi-1)<<endl;
		}
		if(a[i].fi==a[i].se)
			cout<<a[i].fi<<" "<<a[i].se<<" "<<a[i].fi<<endl;
	}

	cout<<endl;
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

    	vector<pii> a(n);

    	rep(i,0,n-1)
    	cin>>a[i].fi>>a[i].se;

    	solve(a);

    }

	return 0;
}

