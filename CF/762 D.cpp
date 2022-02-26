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

int findSecondMax(vi &a)
{
	int mx = 0;
	int size = a.size();

	rep(i,0,size-1)
	{
		if(a[mx]<a[i])
			mx = i;
	}

	int smx = mx==0?1:0;

	rep(i,0,size-1)
	{
		if(a[smx]<a[i] && i!=mx)
			smx = i;
	}

	return a[smx];
}

int findMaxInJ(vvi &a,int j)
{
	int r = a.size();
	int mx = a[0][j];
	rep(i,1,r-1)
	{
		mx = max(mx,a[i][j]);
	}

	return mx;
}

int solve(vvi &a,int r,int c)
{
	int smx = findSecondMax(a[0]);
	rep(i,1,r-1)
	{
		smx = max(smx,findSecondMax(a[i]));
	}

	rep(j,0,c-1)
	{
		smx = min(smx,findMaxInJ(a,j));
	}

	return smx;
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
    	int r,c;
    	cin>>r>>c;

    	vvi a(r,vi(c));

    	rep(i,0,r-1)
    	ininvi(a[i]);

    	cout<<solve(a,r,c)<<endl;

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