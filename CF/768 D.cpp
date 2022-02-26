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

bool check(vi &a,vi &cnt,vi &prefix,int l,int r,int k)
{

}

void solve(vi &a,int k)
{
	int size=a.size();

	vi cnt(size+1,0);
	vi prefix(size+1,0);

	for(int x : a)
		cnt[x]++;

	rep(i,1,size-1)
	{
		prefix[i]=prefix[i-1]+cnt[i];
	}

	int left=0;
	int right=size;

	while(right<=left)
	{
		int mid = (left+right)/2;
		for(int i=1;i<=size-mid+1;i++)
		{
			int l=i;
			int r=l
			if(check(a,cnt,prefix,))
		}
	}

		 	
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