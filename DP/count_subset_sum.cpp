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
/*using recursion*/
int recur(vi &a,int n,int sum)
{
	if(sum==0)
		return 1;
	if(n==0 )
		return 0;

	if(a[n-1]<=sum)
	{
		/*find the count when current element included + when not included*/
		return recur(a,n-1,sum-a[n-1])+recur(a,n-1,sum);
	}
	return recur(a,n-1,sum);

}


/*using bottom up approach the real dp*/
int solve(vi &a,int n,int sum)
{
	int dp[n+1][sum+1];

	rep(i,0,n)
	{
		rep(j,0,sum)
		{
			if(j==0)
				dp[i][j]=1;
			else if(i==0)
				dp[i][j]=0;
			else if(a[i-1]<=j)
				dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
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

    int sum;
    cin>>sum;

    cout<<recur(a,n,sum)<<endl;
    cout<<solve(a,n,sum)<<endl;

	return 0;
}

