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
void print(vi &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
}

void print(vll &a)
{
	for(auto x : a)
		cout<<x<<" ";
	cout<<endl;
}

int solve(vi &a,int k)
{
	int size = a.size();

	if(size==1)
		return a[0]>k?a[0]-k:0;

	sort(a.begin(),a.end());

	int mn=a[0];

	// print(a);

	vll sum(size+1,0);

	for(int i=0;i<size;i++)
		sum[i+1]=sum[i]+a[i];

	// print(sum);
	if(sum[size]<=k)
		return 0;

	int op = INT_MAX;

	for(int i=1;i<size;i++)
	{
		// cout<<((((double)(sum[i+1]-sum[1])-k+a[0]*(size-i+1))/(1.0*size-i+1)))<<endl;
		int x = ceil(((double)(sum[i]-sum[1])-k+a[0]*(size-i+1))/(1.0*size-i+1));
		// cout<<i<<" : "<<x<<" "<<(x+size-i)<<endl;
		// cout<<"(i : "<<i<<")"<<"(x : "<<x<<")(len : "<<(size-i-1)<<endl;
		if(sum[size]-x<=k)
			op = min(op,x);
		else
			op = min(op,x+(size-i));
	}

	return op;
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

		vi a(n);
		ininvi(a);

		cout<<solve(a,k)<<endl;
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