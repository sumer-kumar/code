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


int fun(int a,int b)
{
	int t = 0;

	for(int i=0;i<30;i++)
	{
		t = t | ((a & (1<<i))>0 && (b & (1<<i))>0 ? 1<<i: 0);
	}

	return t;
}

int solve(vi &a,vi &b,int size)
{
	int t = b[0];

	for(int i=1;i<size;i++)
	{
		t = fun(t,b[i]);
	}

	unordered_map<ll,int> um;

	for(int x : b)
	{
		um[x]++;
	}

	//checking phase
	for(int i=0;i<size;i++)
	{
		int x = (int)(a[i] | t);
		if(um.count(x) && um[x]>0)
		{
			um[x]--;
		}
		else
			return -1;
	}

	return t;
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

    	cout<<solve(a,b,n)<<endl;
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