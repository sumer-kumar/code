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


int st[4*100001];
int a[100001];

void create(int si,int ss,int se)
{
	if(ss==se)
	{
		st[si]=1;
		return;
	}

	int mid = (ss+se)/2;

	create(si*2,ss,mid);
	create(si*2+1,mid+1,se);

	st[si] = st[si*2]+st[si*2+1];
}

void update(int si,int ss,int se,int l,int r)
{
	if(r<ss || l>se)
		return;

	if(ss==se)
	{
		a[ss] = (a[ss]+1)%3;
		st[si] = (a[ss]==0);
		return;
	}

	int mid = (ss+se)/2;

	update(si*2,ss,mid,l,r);
	update(si*2+1,mid+1,se,l,r);

	st[si] = st[si*2]+st[si*2+1];
}

int query(int si,int ss,int se,int l,int r)
{
	if(r<ss || l>se)
		return 0;

	if(ss>=l && se<= r)
		return st[si];

	int mid = (ss+se)/2;

	return query(si*2,ss,mid,l,r)+query(si*2+1,mid+1,se,l,r);
}

void solve(int n)
{
	// case-low-range
	int cs,l,r;

	cin>>cs>>l>>r;
	switch(cs)
	{
		case 0: update(1,0,n-1,l,r);
				break;
		case 1:
				cout<<query(1,0,n-1,l,r)<<endl;
				break;
	}

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    cin>>n>>t;

    create(1,0,n-1);

    while(t--)
    {
    	solve(n);
    }
	return 0;
}

