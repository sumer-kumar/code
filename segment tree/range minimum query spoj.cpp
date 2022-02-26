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


void buildst(vi &a,vi &st,int ss,int se,int si)
{
	if(ss==se)
	{
		st[si]=a[ss];
		return; 
	}

	int mid = (ss+se)/2;

	buildst(a,st,ss,mid,si*2);
	buildst(a,st,mid+1,se,si*2+1);

	st[si]=min(st[si*2],st[si*2+1]);
}

int query(vi &st,int si,int ss,int se,int qs,int qe)
{
	if(qs>se || qe<ss)
		return INT_MAX;

	if(ss>=qs && qe>=se)
		return st[si];

	int mid = (ss+se)/2;

	return min(query(st,si*2,ss,mid,qs,qe),query(st,si*2+1,mid+1,se,qs,qe));
}

void solve(vi &a)
{
	int size = a.size();

	int range = size*2+2;

	vi st(range);

	buildst(a,st,0,size-1,1);

	int n;
	cin>>n;

	while(n--)
	{
		int s,e;
		cin>>s>>e;

		cout<<query(st,1,0,size-1,s,e)<<endl;
	}

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;

	vi a(n);
	ininvi(a);

	solve(a);    

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