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

struct node{
	int i,j,sm;
	node(int a,int b,int c)
	{
		i=a;
		j=b;
		sm=c;
	}
};



string solve(vvi &a,int r,int c)
{
	queue<node*> q;

	q.push(new node(0,0,a[0][0]));

	while(!q.empty())
	{
		node* t = q.front();
		q.pop();
		int i=t->i;
		int j=t->j;
		int sm = t->sm;

		if(i==r-1 && j==c-1 && sm==0)
		return "Yes";

		if(i+1<r)
		{
			q.push(new node(i+1,j,sm+a[i+1][j]));
		}
		if(j+1<c)
		{
			q.push(new node(i,j+1,sm+a[i][j+1]));
		}
	}

	return "No";
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