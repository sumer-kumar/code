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

int getNum(bool flag)
{
	return flag==true?2:3;
}

void dfs(vector<pii> a[],int curr,vi &cnt,vi &vis,bool flag=true)
{
	vis[curr]=1;
	for(auto x : a[curr])
	{
		if(vis[x.fi]==false)
		{
			cnt[x.se]=getNum(flag);
			dfs(a,x.fi,cnt,vis,!flag);
		}
	}
}	

void solve(vector<pii> a[],int v)
{
	// cout<<v<<endl;
	rep(i,1,v)
	{
		if(a[i].size()>2)
		{
			cout<<"-1"<<endl;
			return ;
		}
	}

	vi cnt(v+1,0);
	vi vis(v+1,0);

	for(int i=1;i<=v;i++)
	{
		if(a[i].size()==1)
		{
			dfs(a,i,cnt,vis);
		}
	}

	rep(i,1,v-1)
	{
		cout<<cnt[i]<<" ";
	}
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
    	int v;
    	cin>>v;

    	vector<pii> a[v+1];

    	rep(i,1,v-1)
    	{
    		int to,from;
    		cin>>to>>from;

    		a[to].pb({from,i});
    		a[from].pb({to,i});
    	}

    	solve(a,v);

    }

	return 0;
}