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

int recur(vi &a,int n,double k)
{
	if(n==0)
		return 0;

	if(k/a[n-1]>=1)
	{
		return recur(a,n-1,k/a[n-1])+recur(a,n-1,k)+1;
	}
	return recur(a,n-1,k);
}

/*dp nt working*/
int solve(vi& a,int n,int k)
{
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	rep(i,1,n)
	{
		rep(j,1,k)
		{
			dp[i][j] = dp[i][j-1];

			if(a[i-1]<=i && a[i-1]>0)
				dp[i][j]+=dp[i-1][j/a[i-1]];

		}
	}
	return dp[n][k];
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;

    vi a(n);
    rep(i,0,n-1)
    cin>>a[i];

    cout<<recur(a,n,k)<<endl;
    cout<<solve(a,n,k)<<endl;

	return 0;
}

