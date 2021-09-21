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
ll recur(int n,int m)
{
	if(n<0 || m<0)
		return 0;

	if(n==0)
		return 1;

	if(m==0)
		return 1;

	if(dp[n][m]!=-1)
		return dp[n][m];

	int t = recur(n-1,m);
	int p = recur(n,m-1);

	// cout<<"["<<(n-1)<<","<<m<<"] "<<t<<endl;
	// cout<<"["<<(n)<<","<<(m-1)<<"] "<<p<<endl;

	return dp[n][m]=t+p;
}

int solve(int n,int m)
{
	int d[n+1][m+1];
	memset(dp,-1,sizeof(dp));

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(i==0||j==0)
				dp[i][j]=1;
			else
			{
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
			}
		}
	}

	return dp[n][m];
}





/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=3-1;
    int m=7-1;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,m)<<endl;

	return 0;
}

