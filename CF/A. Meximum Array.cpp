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

void solve(vi &a)
{
	int size=a.size();
	
	//for size==1
	if(size==1)
	{
		cout<<"1\n"<<(a[0]==0?1:0)<<endl;
		return;
	}

	vector<queue<int>> q(size+1);

	rep(i,0,size-1)
	{
		q[a[i]].push(i);
	}

	vi res;
	int start=0;

	while(start<size)
	{
		int end=start;
		int cnt=0;
		for(int i=0;i<=size;i++)
		{
			while(!q[i].empty() && q[i].front()<start)
				q[i].pop();
			if(q[i].empty())
				break;
			end=max(end,q[i].front());
			q[i].pop();
			cnt++;
		}

		res.pb(cnt);
		start=end+1;
	}
	cout<<res.size()<<endl;
	for(int x : res)
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

		solve(a);
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