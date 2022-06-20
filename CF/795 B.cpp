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



/*
void solve(vi &a,int size)
{
	unordered_map<int,vi> um;
	rep(i,0,size-1)
	um[a[i]].pb(i);

	vi res(size,0);
	for(auto x : um)
	{
		if(x.second.size()<2)
		{
			cout<<"-1"<<endl;
			return ;
		}

		int sizei = x.second.size();

		res[x.second.back()] = x.second[0];

		rep(i,1,sizei-1)
		{
			res[x.second[i-1]] = x.second[i]; 
		}
	}

	for(int x : res)
	{
		cout<<x+1<<" ";
	}
	cout<<endl;
}*/

void rotate(vi &a,int l,int r)
{
	if(r-l==0)
		return ;

	int t = a[l];
	rep(i,l,r-1)
	{
		a[i]=a[i+1];
	}
	a[r]=t;
}

void solve(vi &a,int size)
{

	int i=0;
	
	int j=0;


	vi p(size,0);
	rep(k,0,size-1)
		p[k]=k+1;

	while(j<size)
	{
		while(j<size && a[i]==a[j])
			j++;
		if(j-i<=1)
		{
			cout<<"-1"<<endl;
			return;
		}
		rotate(p,i,j-1);
		i=j;
	}

	for(int x : p)
		cout<<x<<" ";
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
    	int n;
    	cin>>n;
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