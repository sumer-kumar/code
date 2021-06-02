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

int solve(vvi a,int n,int m)
{
	vvi dp(n+1,vi(m+1,0));

	rep(i,1,n)
	{
		rep(j,1,m)
		{
			if(a[i-1][j-1]==1)
			{
				dp[i][j]=1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
	}

	int ans =0;
	rep(i,0,n)
	rep(j,0,m)
	ans = max(ans,dp[i][j]);

	return ans;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;

    vvi a(n,vi(m));

    rep(i,0,n-1)
    rep(j,0,m-1)
    cin>>a[i][j];

    cout<<solve(a,n,m)<<endl;

	return 0;
}

