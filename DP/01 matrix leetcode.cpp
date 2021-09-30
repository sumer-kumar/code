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

void printVVI(vvi &a)
{
	for(auto x : a)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}
	cout<<endl;
}

/*not correct*/
int recur(vvi &a,vvi &dp,vector<vector<bool>> &vis,int i,int j,int r,int c)
{
	if(i<0 || j<0 || i>=r || j>= r || vis[i][j]==true)
		return 100000;

	if(dp[i][j]!=-1)
		return dp[i][j];


	if(a[i][j]==0)
		return dp[i][j]=0;

	int res = 100000;

	vis[i][j]=true;
	res = min(res,1+recur(a,dp,vis,i+1,j,r,c));
	res = min(res,1+recur(a,dp,vis,i,j+1,r,c));
	res = min(res,1+recur(a,dp,vis,i-1,j,r,c));
	res = min(res,1+recur(a,dp,vis,i,j-1,r,c));
	vis[i][j]=false;

	return dp[i][j]=res;
}

void solve(vvi &a)
{
	int r = a.size();
	int c = a[0].size();

	vvi dp(r,vi(c,-1));
	vector<vector<bool>> vis(r,vector<bool>(c,false));

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			if(a[i][j]==1)
			recur(a,dp,vis,i,j,r,c);
		}
	}

	for(auto &x : dp)
		for(int &p : x)
			if(p==-1)
				p=0;


	printVVI(dp);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
	  1 2 3 4 5 6 7 8 9 10
	[[1,0,1,1,0,0,1,0,0,1], 1
	 [0,1,1,0,1,0,1,0,1,1], 2
	 [0,0,1,0,1,0,0,1,0,0], 3
	 [1,0,1,0,1,1,1,1,1,1], 4
	 [0,1,0,1,1,0,0,0,0,1], 5
	 [0,0,1,0,1,1,1,0,1,0], 6
	 [0,1,0,1,0,1,0,0,1,1], 7
	 [1,0,0,0,1,1,1,1,0,1], 8
	 [1,1,1,1,1,1,1,0,1,0], 9
	 [1,1,1,1,0,1,0,0,1,1]] 10

*/

    vvi a = {
    	{1,0,1,1,0,0,1,0,0,1},
    	{0,1,1,0,1,0,1,0,1,1},
    	{0,0,1,0,1,0,0,1,0,0},
    	{1,0,1,0,1,1,1,1,1,1},
    	{0,1,0,1,1,0,0,0,0,1},
    	{0,0,1,0,1,1,1,0,1,0},
    	{0,1,0,1,0,1,0,0,1,1},
    	{1,0,0,0,1,1,1,1,0,1},
    	{1,1,1,1,1,1,1,0,1,0},
    	{1,1,1,1,0,1,0,0,1,1},
    };

    printVVI(a);

    solve(a);

	return 0;
}

