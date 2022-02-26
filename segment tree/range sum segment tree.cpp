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

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

#define MAXN 100001

int st[4*MAXN];
int lazy[4*MAXN];


/*si is segment index*/
void create_st(vi &a,int ss,int se,int si)
{
	if(ss==se)
	{
		st[si] = a[ss];
		return;
	}

	int mid = (ss+se)/2;

	create_st(a,ss,mid,si*2);
	create_st(a,mid+1,se,si*2+1);

	st[si] = st[si*2]+st[si*2+1];
}

/*for queries to get sum of range l-r*/
int query(int si,int ss,int se,int l,int r)
{

	//for lazy propagation
	if(lazy[si]!=0)
	{
		//pending increment
		int pen_incr = lazy[si];
		lazy[si]=0;

		st[si] += (se-ss+1)*pen_incr;

		if(ss!=se)
		{
			lazy[si*2] += pen_incr;
			lazy[si*2+1] += pen_incr;
		}
	}

	//if current segment is completely outside of the range
	if(ss>r || se<l)
		return 0;

	//if completely inside the segment then return the value 
	if(ss>=l && se<=r)
		return st[si];


	int mid = (ss+se)/2;

	return query(si*2,ss,mid,l,r)+query(si*2+1,mid+1,se,l,r);
}

/*update increment [l,r] all with values v*/
void update(int si,int ss,int se,int l,int r,int v)
{
	//for lazy propagation
	if(lazy[si]!=0)
	{
		//pending increment
		int pen_incr = lazy[si];
		lazy[si]=0;

		st[si] += (se-ss+1)*pen_incr;

		if(ss!=se)
		{
			lazy[si*2] += pen_incr;
			lazy[si*2+1] += pen_incr;
		}
	}

	if(ss>r || se<l)
		return;

	if(ss>=l && se<=r)
	{
		st[si] += (se-ss+1)*v;

		if(ss!=se)
		{
			lazy[si*2] += v;
			lazy[si*2+1] += v;
		}
		return;
	}

	int mid = (ss+se)/2;

	update(si*2,ss,mid,l,r,v);
	update(si*2+1,mid+1,se,l,r,v);

	st[si] = st[si*2]+st[si*2+1];
}


void solve(vi &a)
{
	int size = a.size();
	memset(lazy,0,sizeof(lazy));
	create_st(a,0,size-1,1);


	cout<<"sum query [1,3] : "<<query(1,0,size-1,1,3)<<endl;
	rep(i,1,2*size+2)
	cout<<st[i]<<" ";
	cout<<endl;

	update(1,0,size-1,1,3,2);
	cout<<"sum query [1,3] : "<<query(1,0,size-1,1,3)<<endl;

	rep(i,1,2*size+1)
	cout<<st[i]<<" ";
	cout<<endl;

	update(1,0,size-1,1,1,10);

	cout<<"sum query [1,1] : "<<query(1,0,size-1,1,1)<<endl;
	rep(i,1,2*size+1)
	cout<<st[i]<<" ";
	cout<<endl;


}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1, 3, 5, 7, 9, 11};

    solve(a);

	return 0;
}

