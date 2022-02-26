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
int CeilIndex(vi &v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}

bool cmp(pii &a,pii &b)
{
	if(a.fi==b.fi)
		return a.se<b.se;
	return a.fi<b.fi;
}
/*dp + binary search O(nlogn)*/
int lis(vi& a,int n)
{
	vi dp;
	dp.pb(a[0]);

	rep(i,1,n-1)
	{
		if(a[i]>dp.back())
			dp.pb(a[i]);
		else
		{
			int ind = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
			dp[ind] = a[i];
		}
	}
	return dp.size();
}

int recur(vi &b)
{
	int size = b.size();
	vector<pii> a(size);

	rep(i,0,size-1)
	{
		a[i].fi=b[i];
		a[i].se=i;
	}

	sort(a.begin(),a.end(),cmp);

	vi aa(size);

	rep(i,0,size-1)
	{
		aa[i]=a[i].se;
	}
	return lis(aa,size);
}

int solve(vi &a,vi &b)
{
	// cout<<"a : "<<lis(a,a.size())<<endl;
	// cout<<"b : "<<lis(b,b.size())<<endl;
	return recur(a)+recur(b);
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
    	int n,m;
    	cin>>n>>m;

    	vi a(n),b(m);
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