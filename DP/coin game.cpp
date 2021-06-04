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

int recur(int n,int x,int y)
{
	if(n==0)
		return false;
	if(n==1)
		return true;

	if(n-1>=0 && !recur(n-1,x,y))
		return true;
	if(n-x>=0 && !recur(n-x,x,y))
		return true;
	if(n-y>=0 && !recur(n-y,x,y))
		return true;
	return false;
}


bool solve(int n,int x,int y)
{
	vi dp(n+1);
	dp[0]=false;
	dp[1]=true;

	rep(i,2,n)
	{
		if(i-1>=0 && !dp[i-1])
			dp[i]=true;
		else if(i-x>=0 && !dp[i-x])
			dp[i]=true;
		else if(i-y>=0 && !dp[i-y])
			dp[i]=true;
		else
			dp[i]=false;
	}	
	return dp[n];
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;

    cout<<recur(n,x,y)<<endl;
    cout<<solve(n,x,y)<<endl;



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