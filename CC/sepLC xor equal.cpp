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


void solve(vi &a,int n,int x)
{
	unordered_map<int,int> um1;
	rep(i,0,n-1)
	um1[a[i]]++;

	if(x==0)
	{
		int mx = 0;
		for(auto p : um1)
		{
			mx = max(mx,p.se);
		}
		cout<<mx<<" "<<"0"<<endl;
		return ;
	}

	unordered_map<int,int> um2=um1;

	rep(i,0,n-1)
	um2[a[i]^x]++;

	int res_count = 0;
	int res_op = 0;

	for(auto p : um1)
	{
		// cout<<p.fi<<" "<<um2[p.fi]<<" "<<p.se<<"\n"<<endl;
		if(um2[p.fi] > res_count)
		{
			res_count = um2[p.fi];
			res_op = um2[p.fi]-p.se;
		}
		else if(um2[p.fi] == res_count)
		{
			res_op = min(res_op,um2[p.fi]-p.se);
		}
	}

	for(auto p : um2)
	{
		if(um1.find(p.fi)==um1.end())
		{
			if(res_count<p.se)
			{
				res_count=p.se;
				res_op=p.se;
			}
			else if(res_count==p.se)
			{
				res_op=min(res_op,p.se);
			}
		}
	}

	cout<<res_count<<" "<<res_op<<endl;
	// cout<<"----------------------"<<endl;

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
    	int n,x;
    	cin>>n>>x;

    	vi a(n);
    	ininvi(a);

    	solve(a,n,x);
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