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

int recur(vi &a,int i,int k,int n)
{
	if(i==n-1)
		return 0;

	int ans = INT_MAX;
	int limit=0;
	rep(it,i,n-2)
	{
		limit += a[it];
		if(limit>k)
			break;
		ans = min(ans,recur(a,it+1,k,n)+k-limit);
		limit++;
	}
	return ans;
}

/*using memoization*/
vi dp(1001,-1);
int memo(vi &a,int i,int k,int n)
{
	if(dp[i]!=-1)
		return dp[i];

	if(i>=n-1)
		return dp[i]=0;


	int ans = INT_MAX;
	int limit=0;
	rep(it,i,n-1)
	{
		limit += a[it];
		if(limit>k)
			break;

		ans = min(ans,memo(a,it+1,k,n)+k-limit);
		limit++;
	}
	return dp[i]=ans;
}



int recurFunc(vi &a,int n,int k)
{
	return recur(a,0,k,n);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;

    vi a(n);
    ininvi(a);

    cin>>k;

    cout<<recurFunc(a,n,k)<<endl;
    cout<<memo(a,0,k,n)<<endl;


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