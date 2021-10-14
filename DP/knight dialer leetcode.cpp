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

int dp[10][10][5001];
int recur(vvi &a,int i,int j,int n)
{

	if(i<0 || i>=4 || j<0 || j>=3 || a[i][j]==-1)
		return 0;

	if(n==0)
	{
		return 1;
	}

	if(dp[i][j][n]!=-1)
		return dp[i][j][n];

	int res = 0;

	res = (1ll*res + 1ll*recur(a,i+2,j+1,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i+2,j-1,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i-2,j+1,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i-2,j-1,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i+1,j+2,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i+1,j-2,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i-1,j+2,n-1))%mod;
	res = (1ll*res + 1ll*recur(a,i-1,j-2,n-1))%mod;

	return dp[i][j][n]=res;
}


int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	vvi a = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{-1,0,-1},
	};

	int res = 0;

	rep(i,0,3)
	{
		rep(j,0,2)
		{
			if(a[i][j]!=-1)
				res = res + recur(a,i,j,n-1);
		}
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=3;

    cout<<solve(n)<<endl;

	return 0;
}

