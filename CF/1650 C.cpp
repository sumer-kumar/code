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

bool cmp(vi &a,vi &b)
{
	return a[1]<b[1];
}

void solve(vvi &a,int size,int pair)
{
	sort(a.begin(),a.end(),cmp);

	sort(a.begin(),a.begin()+2*pair);

	int sum = 0;
	rep(i,0,2*pair-1)
	{
		sum += a[i][1];
	}

	int i=0;
	int j=2*pair-1;


	cout<<sum<<endl;
	while(i<j)
	{
		cout<<a[i++][2]<<" "<<a[j--][2]<<endl;
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
    	int pair,size;
    	cin>>pair>>size;
    	vvi a(size,vi(3,0)); // x coordinate <-> weight

    	rep(i,0,size-1)
    	{
    		cin>>a[i][0]>>a[i][1];
    		a[i][2]=i+1;
    	}

    	solve(a,size,pair);
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