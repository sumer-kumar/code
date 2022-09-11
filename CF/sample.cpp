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


void space(int n,char x)
{
	while(n--)
	{
		cout<<x<<" ";
	}
}

void solve2(vi &a)
{
	int n = a.size();
	vi sm(n+1,0);
	for(int i=0;i<n;i++)
		sm[i+1] = sm[i] + a[i];

	for(int i=n;i>=1;i--)
	{
		space(sm[i-1],' ');
		space(a[i-1]+1,'*');
		cout<<endl;
		for(int j=0;j<a[i-1]-1;j++)
		{
			space(sm[i-1],' ');
			space(1,'*');
			cout<<endl;
		}
	}
	cout<<"*"<<endl;
}


int inc(vi &a)
{
	int sm = 0;
	int mn = a[0];

	int low = 0;
	int size = a.size();
	for(int i=1;i<size;i++)
	{
		if(a[i-1]<a[i])
		{
			mn = min(mn,a[i]);
			if(i==size-1)
				sm += mn*(i-low+1);
		}
		else
		{
			if(i-low!=1)
				sm += mn*(i-low);
			mn = a[i];
			low = i;
		}
	}

	return sm;
}

int solve(vi &a)
{
	vi b = a;
	reverse(b.begin(),b.end());
	return inc(a) + inc(b);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {21,12,27,40,9,13};

    cout<<solve(a)<<endl;

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