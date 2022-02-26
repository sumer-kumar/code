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

ll solve(vi &a,vi &b)
{
	int size=a.size();
	int mx1=a[0];
	int mx2=b[0];

	rep(i,0,size-1)
	mx1=max(mx1,a[i]);

	rep(i,0,size-1)
	mx2=max(mx2,b[i]);

	if(mx1<mx2)
		return solve(b,a);

	int ind = 0;
	rep(i,0,size-1)
	if(mx1==a[i]){
		ind=i;
		break;
	}

	rep(i,0,size-1)
	{
		if(a[i]<b[i] && i!=ind)
		{
			swap(a[i],b[i]);
		}
	}

	int mx3=b[0];

	rep(i,0,size-1)
	mx3=max(mx3,b[i]);

	return mx3*mx1;

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

		vi a(n),b(n);

		ininvi(a);
		ininvi(b);

		cout<<solve(a,b)<<endl;
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