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
// int dp[1111][1111];
// int recur(vi &a,int n,int sum)
// {

// 	if(sum==0)
// 		return 0;

// 	if(n<=0)
// 		return INT_MAX-1;

// 	if(dp[n][sum]!=-1)
// 		return dp[n][sum];

// 	if(sum-a[n-1]>=0)
// 	{
// 		return dp[n][sum] = min(1+recur(a,n,sum-a[n-1]),recur(a,n-1,sum));
// 	}

// 	return dp[n][sum] = recur(a,n-1,sum);
// }


int solve(int n)
{
	//generate perfect square numbers

	// memset(dp,-1,sizeof(dp));
	vector<int> a;
	int x = 1;

	while(x*x<=n)
	{
		a.pb(x*x);
		// cout<<a.back()<<" ";
		x++;
	}
	// cout<<endl;

	int m = a.size();

	vvi dp(m+1,vector<int>(n+1,0));

	rep(i,0,m)
	{
		rep(j,0,n)
		{
			if(j==0)
				dp[i][j]=0;
			else if(i==0)
				dp[i][j]=9999999;
			else if(j-a[i-1]>=0)
				dp[i][j] = min(1+dp[i][j-a[i-1]],dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];

			// cout<<dp[i][j]<<' ';
		}
		// cout<<endl;
	}

	// return recur(a,a.size(),n);
	return dp[m][n];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=12;

    cout<<solve(n)<<endl;

    // rep(i,0,3)
    // {
    // 	rep(j,0,12)
    // 	cout<<dp[i][j]<<' ';
    // 	cout<<endl;
    // }

	return 0;
}

