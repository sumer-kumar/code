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

enum status {need_camera,has_camera,covered,not_need_camera};

int recur(vi a[],int curr,int parent,int &cnt)
{
	bool flag1 = false;
	bool flag2 = false;

	if(a[curr].size()==1)
		return need_camera;

	for(auto &x : a[curr])
	{
		if(x!=parent)
		{
			int t = recur(a,x,curr,cnt);
			if(t==need_camera)
				flag1=true;
			if(t==has_camera)
				flag2=true;
		}
	}

	if(flag1){
		cnt++;
		return has_camera;
	}

	if(flag2)
		return covered;

	return need_camera;
}

vector<vector<int>> dp;
void dfs(vi a[],int par,int one)
{
	dp[par][0] = 0;
	dp[par][1] = 1;

	for(int e : a[par])
	{
		if(e==one) continue;
		dfs(a, e,par);
		dp[par][0] += dp[e][1];
		dp[par][1] += min(dp[e][1],dp[e][0]);
	}
}

int solve(vvi &ed,int n)
{
	dp.assign(n + 1, vector<int>(2, 0));

	vi a[n+1];
	for(auto &x : ed)
	{
		a[x[0]].push_back(x[1]);
		a[x[1]].push_back(x[0]);
	}
	
	dfs(a, 1, -1);

	return min(dp[1][0], dp[1][1]);	
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi ed = {
    	{1,2},
    	{1,3},
    	{1,4}
    };

    int n = 4;
    cout<<solve(ed,n)<<endl;

	return 0;
}

