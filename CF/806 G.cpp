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

ll recur(vll &a,int curr,int &n,int k,int h,vvll &dp)
{

	if(curr==n || h>=32)
		return 0;

	if(dp[curr][h]!=-1)
		return dp[curr][h];

	return dp[curr][h]= max(
			1ll*(a[curr]>>h) - 1ll*k + 1ll*recur(a,curr+1,n,k,h,dp),
			1ll*(a[curr]>>(h+1)) + 1ll*recur(a,curr+1,n,k,h+1,dp)
		);
}


ll solve(vll &a,int n,int k)
{
	vvll dp(n+1,vll(40,-1));
	return recur(a,0,n,k,0,dp);
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
    	int n,k;
    	cin>>n>>k;

    	vll a(n);
    	inllvi(a);

    	cout<<solve(a,n,k)<<endl;
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