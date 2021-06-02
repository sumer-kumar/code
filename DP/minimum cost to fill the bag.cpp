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

int INF = 100000000;
/*giving wrong ans*/
int recur(vi &a,int n,int W)
{
	if(W==0)
		return 0;
	if(n==0)
		return INF;

	if(n-1<W && a[n-1]!=1)
	{
		int inc = recur(a,n,W-(n))+a[n-1];
		int exc = recur(a,n-1,W);
		// cout<<inc<<" "<<exc<<endl;
		return min(inc,exc);
	}
	return recur(a,n-1,W);
}


// vvi dp(1001,vi(1001,-1));

// int memo(vi &a,int n,int W)
// {
// 	if(W==0)
// 		return 0;
// 	if(n==0)
// 		return INF;
// 	if(dp[n][W]!=-1)
// 		return dp[n][W];

// 	if(W-n>=0 && a[n-1]!=1)
// 	{	
// 		int inc = memo(a,n,W-(n))+a[n-1];
// 		int exc = memo(a,n-1,W);
// 		return dp[n][W]= min(inc,exc);
// 	}
// 	return dp[n][W]=memo(a,n-1,W);
// }

/*using concept of unbound knapsack*/
int solve(vi &a,int n,int W)
{	
	vi dp(W+1,10000);
	dp[0]=0;

	rep(i,1,W)
	{
		for(int j=0;j<i && j<n;j++)
		{
			if(a[j]!=-1 && i-j>0)
			{
				dp[i]=min(dp[i],dp[i-(j+1)]+a[j]);
			}
			// for(int x : dp)
			// 	cout<<x<<" ";
			// cout<<endl;
		}
	}
	return dp[W];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,W;
    cin>>n>>W;

    vi a(n);
    rep(i,0,n-1)
    cin>>a[i];

    cout<<recur(a,n,W)<<endl;
    cout<<solve(a,n,W)<<endl;

	return 0;
}

