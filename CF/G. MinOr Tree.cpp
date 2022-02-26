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

int dfs(vector<pii> a[],int curr,vector<bool> &vis,int bit,int nans)
{
	vis[curr]=true;

	for(auto x : a[curr])
	{
		if(vis[x.fi]==false && ((1<<bit) & x.se)==0 && ((nans & x.se)==0)) 
		{
			dfs(a,x.fi,vis,bit,nans);
		}
	}
}

bool check(vector<pii> a[],int v,int bit,int nans)
{
	vector<bool> vis(v+1,false);
	dfs(a,1,vis,bit,nans);

	for(int i=1;i<=v;i++)
	{
		if(vis[i]==false)
			return false;
	}
	return true;
}

int solve(vector<pii> a[],int v,int e)
{
	int ans = 0;
	int nans=0;
	for(int i=30;i>=0;i--)
	{
		// cout<<check(a,v,20)<<endl;
		if(check(a,v,i,nans))
		{
			nans = nans|(1<<i);
			continue;
		}
		ans = ans|(1<<i);
	}

	return ans;
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
    	int v,e;
    	cin>>v>>e;

    	vector<pii> a[v+1];

    	rep(i,0,e-1)
    	{
    		int from,to,weight;
    		cin>>from>>to>>weight;
    		a[from].pb({to,weight});
    		a[to].pb({from,weight});
    	}

    	cout<<solve(a,v,e)<<endl;
    }

	return 0;
}

