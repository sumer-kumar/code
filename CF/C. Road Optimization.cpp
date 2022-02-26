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


// int dp[501][501];
// int recur(vi &a,vi &b,int curr,int last,int k)
// {
// 	if(curr==a.size()-1)
// 		return 0;

// 	if(dp[curr][k]!=-1)
// 		return dp[curr][k];

// 	//if removing the current stop
// 	if(k>=1)
// 	{
// 		int m1 = b[last]*(a[curr+1]-a[curr]) + recur(a,b,curr+1,last,k-1);
// 		int m2 = b[curr]*(a[curr+1]-a[curr]) + recur(a,b,curr+1,curr,k);
// 		return dp[curr][k] = min({m1,m2});
// 	}

// 	return dp[curr][k]=b[curr]*(a[curr+1]-a[curr]) + recur(a,b,curr+1,curr,k);
// }

ll dp[505][505];
ll recur(vi &a,vi &b,int curr,int k)
{
	if(curr>=a.size()-1)
		return 0;

	// cout<<curr<<endl;

	if(dp[curr][k]!=-1)
		return dp[curr][k];

	ll res = INT_MAX;
	for(int i=0;i<=k;i++)
	{
		if(curr+i+1>=a.size()) break;
		// cout<<(b[curr])<<" "<<a[curr+i+1]<<" "<<a[curr]<<" "<<k<<" "<<curr<<" "<<i<<endl;
		res = min(res, 1ll*b[curr]*(a[curr+i+1]-a[curr])+1ll*recur(a,b,curr+i+1,k-i));
	}

	// cout<<res<<" --"<<endl;

	return dp[curr][k]=res;
}

int solve(vi &a,vi &b,int l,int k)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();
	a.pb(l);
	b.pb(0);

	return recur(a,b,0,k);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,l,k;
	cin>>n>>l>>k;    

	vi a(n),b(n);

	ininvi(a);
	ininvi(b);

	cout<<solve(a,b,l,k)<<endl;

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