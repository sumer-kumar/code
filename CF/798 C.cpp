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

int recur(vi a[],int curr,int parent,vi &childs)
{
	int child = 0;
	for(int x : a[curr])
	{
		if(x!=parent)
		{
			child += recur(a,x,curr,childs);
		}
	}
	childs[curr] = child;
	return child+1;
}
//i can save one of them at each level
int dfs(vi a[],int curr,int parent,vi &childs)
{
	int res = 0;
	int tt = 0;

	vi conn(a[curr].size(),0);

	for(int i=0;i<a[curr].size();i++)
	{
		if(a[curr][i]!=parent)
		{
			conn[i] = dfs(a,a[curr][i],curr,childs);
		}
	}
	
	for(int x : conn)
	tt += x;

	for(int i=0;i<conn.size();i++)
	{
		if(a[curr][i]!=parent)
		{
			res = max(res, tt - conn[i] + childs[a[curr][i]]);
		}
	}	

	return res;
}

int solve(vi a[],int size)
{
	vi childs(size,0);
	recur(a,0,-1,childs);

	return dfs(a,0,-1,childs);
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

    	vi a[n];
    	rep(i,0,n-2)
    	{
			int to,from;
			cin>>to>>from;
			to--;from--;
			a[to].pb(from);
			a[from].pb(to);
    	}

    	cout<<solve(a,n)<<endl;
    }

	return 0;
}

