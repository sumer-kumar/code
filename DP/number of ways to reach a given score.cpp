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

/*recursive*/
int recur(vi& a,int n,ll M)
{

	if(M==0)
	return 1;

	if(n==0)
	return 0;	

	if(M-a[n-1]>=0)
	{
		return recur(a,n,M-a[n-1])+recur(a,n-1,M);
	}
	return recur(a,n-1,M);
}

int solve(vi &a,int n,ll M)
{
	vvll dp(n+1,vll(M+1));

	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=M;j++)
		{
			if(j==0)
				dp[i][j]=1;
			else if(i==0)
				dp[i][j]=0;
			else if(j-a[i-1]>=0)
				dp[i][j]=dp[i][j-a[i-1]]+dp[i-1][j];
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][M];
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;

    vi a = {3,5,10};

    cout<<recur(a,3,n)<<endl;
    cout<<solve(a,3,n)<<endl;

	return 0;
}

