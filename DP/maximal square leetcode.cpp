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

int dp[333][333];
int recur(vvi &a,int r,int c,int &res)
{
	if(r<0 || c<0)
		return 0;

	if(dp[r][c]!=-1)
		return dp[r][c];

	if(a[r][c]==1)
	{
		int t = dp[r][c] = 1 + min(
								recur(a,r-1,c,res),
								min(
									recur(a,r,c-1,res),
									recur(a,r-1,c-1,res)
									)
								);
		
		res = max(res,t);
		return t;
	}


	recur(a,r-1,c,res);
	recur(a,r,c-1,res);

	return dp[r][c] = 0;
}

int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size()-1;
	int c = a[0].size()-1;

	int res = 0;

	recur(a,r,c,res);


	// rep(i,0,r)
	// {
	// 	rep(j,0,c)
	// 	cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }


	return res*res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//[["1","0","1","0","0"],
    //["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    vvi a = {
    	{1,0,1,0,0},
    	{1,0,1,1,1},
    	{1,1,1,1,1},
    	{1,0,0,1,0}
    };

    cout<<solve(a)<<endl;

	return 0;
}

