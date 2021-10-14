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

int dp[111][111];
int recur(vvi &a,int i,int j,int r,int c)
{
	if(i>=r || j<0 || j>=r)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int res = a[i][j]+recur(a,i+1,j,r,c);
	// cout<<"["<<i<<","<<j<<"]"<<" down : "<<res<<endl;

	if(j+1<c)
	{
		res = min(res,a[i][j]+recur(a,i+1,j+1,r,c));
		// cout<<"["<<i<<","<<j<<"]"<<" right : "<<res<<endl;
	}

	if(j-1>=0)
	{
		res = min(res,a[i][j]+recur(a,i+1,j-1,r,c));
		// cout<<"["<<i<<","<<j<<"]"<<" left : "<<res<<endl;
	}
	return dp[i][j]=res;
}


int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size();
	int c = a[0].size();
	int res = INT_MAX;

	rep(j,0,c-1)
	{
		res = min(res,recur(a,0,j,r,c));
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*[[2,1,3],[6,5,4],[7,8,9]]*/
    /*[-19,57],[-40,-5]*/
	 /*[[100,-42,-46,-41],[31,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]*/

	vvi a = {
    	{2,1,3},
    	{6,5,4},
    	{7,8,9}
		// {-19,57},
		// {-40,-5}
		// {100,-42,-46,-41},
		// {31,97,10,-10},
		// {-58,-51,82,89},
		// {51,81,69,-51}
    };

	cout<<solve(a)<<endl;

	return 0;
}
