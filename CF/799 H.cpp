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
void ininarr(int a[],int size);
void ininvi(vi &a,int size=0);
void inllarr(ll a[],ll n);
void inllvi(vll &a,ll size=0);

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

void solve(vi &a,int size)
{
	map<int,vi> um;

	rep(i,0,size-1)
	um[a[i]].pb(i);

	int aa,l,r;
	
	int benefit = 1;

	for(auto x : um)
	{
		vi t = x.second;
		if(t.size()<2)
			continue;

		vi sm(t.size(),0);
		sm[0]=1;
		// for(int x : t)
		// 	cout<<x<<" ";
		// cout<<endl;
		rep(i,1,t.size()-1)
		{
			sm[i] = sm[i-1] + (t[i-1]+1==t[i] ? 1: (t[i-1]-t[i]+2));
		}	

		// cout<<x.first<<endl;
		// for(int x : sm)
		// 	cout<<x<<" ";
		// cout<<endl;

		int mx = sm.size()-1;
		for(int i=sm.size()-2;i>=0;i--)
		{
			if(sm[mx]<=sm[i])
				mx = i;
			if(benefit < sm[mx]-sm[i]+1)
			{
				benefit = sm[mx]-sm[i]+1;
				aa = a[t[i]];
				l = t[i];
				r = t[mx];
			}
		}
	}

	if(benefit==1)
	{
		cout<<a[0]<<" "<<1<<" "<<1<<endl;
		return;
	}

	cout<<aa<<" "<<l+1<<" "<<r+1<<" "<<endl;

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

		vi a(n);
		ininvi(a);

		solve(a,n);
	}   

	return 0;
}







/******INPUT THINGS*********/
void ininarr(int a[],int size)
{
	rep(i,0,size-1)
	{
		cin>>a[i];
	}
}

void ininvi(vi &a,int size)
{
	if(!size)
		size = a.size();
	rep(i,0,size-1)
	cin>>a[i];
}

void inllarr(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cin>>a[i];
}

void inllvi(vll &a,ll size)
{
	if(!size)
		size=a.size();
	for(ll i=0;i<size;i++)
		cin>>a[i];
}