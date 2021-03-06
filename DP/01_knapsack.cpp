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
/*usign recursion*/
int recur(vi &w,vi &v,int n,int W)
{
	if(n<=0 || W<=0)
		return 0;

	if( w[n-1] <= W)
	{
		int inc = v[n-1]+recur(w,v,n-1,W-w[n-1]);
		int exc = recur(w,v,n-1,W);
		return max(inc,exc);
	}
	else/*not include*/
	{
		return recur(w,v,n-1,W);
	}

}

/*using memoization*/
/*2d matrix because n and w are variables*/
vvi t(1001,vi(1001,-1)); /*(n+1)*(w+1)*/
int fun(vi &w,vi &v,int n,int W)
{
	if(n<=0 || W<=0)
		return 0;


	if(t[n][W]!=-1)
		return t[n][W];

	if( w[n-1] <= W)
	{
		int inc = v[n-1]+fun(w,v,n-1,W-w[n-1]);
		int exc = fun(w,v,n-1,W);
		t[n][W] = max(inc,exc);
		return t[n][W];
	}
	else/*not include*/
	{
		t[n][W] = fun(w,v,n-1,W);
		return t[n][W];
	}
}

/*using top down upproah the real dp*/
/*here we go*/


/*int solve(int w[],int v[],int W)  */
int solve(vi &w,vi &v,int n,int W)
{
	vvi dp(n+1,vi(W+1));/*column for W and row for items*/
	/*int dp[n+1][W+1]*/

	rep(i,0,n)
	{
		rep(j,0,W)
		{
			if(i==0||j==0)/*base condition in recursion*/
			{
				dp[i][j]=0;
			}
			else if(w[i-1]<=j)
			{
				/*first include and second dont*/
				dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j] = dp[n-1][j];
			}
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][W];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi v(n);
    vi w(n);

    rep(i,0,n-1)
    cin>>w[i]>>v[i];

    int W;
    cin>>W;

    // cout<<recur(w,v,n,W)<<endl;
    // cout<<fun(w,v,n,W)<<endl;
    cout<<solve(w,v,n,W);


	return 0;
}

