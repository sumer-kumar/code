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
#define lint long



void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}



int solve(vi &a,int k)
{
	int size = a.size();
	long sum = 0;

	sort(a.begin(),a.end());

	// 0 1 2 3 4 5 6 7 8
	rep(i,0,size-2*k-1)
	{
		sum += a[i];
	}

	vi left;
	vi right;

	rep(i,size-2*k,size-k-1)
	{
		left.pb(a[i]);
	}

	rep(i,size-k,size-1)
	{
		right.pb(a[i]);
	}
	
	rep(i,0,k-1)
	{
		sum += left[i]/right[i];
	}

	return sum;
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
