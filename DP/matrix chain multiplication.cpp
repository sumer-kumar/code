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

int p = 0;
/*recursive approach */
int recur(vi &a,int i,int j)
{
	if(i>=j) return 0;
	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		int t = recur(a,i,k) + recur(a,k+1,j) + a[i-1]*a[k]*a[j];
		ans = min(ans,t);
	}
	return ans;
}

/*memoization*/
vvi lp(1001,vi(1001,-1));
int memo(vi &a,int i,int j)
{
	if(i>=j) return 0;
	if(lp[i][j]!=-1)
		return lp[i][j];
	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		int t = memo(a,i,k) + memo(a,k+1,j) + a[i-1]*a[k]*a[j];
		ans = min(ans,t);
	}
	lp[i][j] = ans;
	return ans;
}

/*bottom up approach*/
int solve(vi &a,int n)
{
	vvi dp(n+1,vi(n+1));
	rep(L,2,n)
	{
		rep(i,1,n-L)
		{	int j = i+L-1;
			dp[i][j]=INT_MAX;
			cout<<i<<" : "<<j<<endl;
			if(i>=j)
				dp[i][j]=0;
			rep(k,i,j-1)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
			}
	for(auto x : dp)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}
	cout<<"\n\n";
		}
	}

	return dp[1][n-1];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vi a(n);
    rep(i,0,n-1)
    cin>>a[i];
    cout<<recur(a,1,n-1)<<endl;
    cout<<memo(a,1,n-1)<<endl;
    cout<<solve(a,n)<<endl;

    rep(i,0,n)
    {
    	rep(j,0,n)
    	cout<<lp[i][j]<<" ";
    	cout<<endl;
    }

	return 0;
}

