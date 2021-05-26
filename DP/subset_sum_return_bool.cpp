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

/*recursive approach*/
bool recur(vi& a,int n,int sum)
{
	/*base conditions*/
	if(sum == 0)
		return true;
	if(n==0 && sum!=0)
		return false;

	/*choice conditions*/
	if(a[n-1]<=sum)
		return recur(a,n-1,sum-a[n-1]) || recur(a,n-1,sum);
	return recur(a,n-1,sum);
}

/*top down appraoch*/
bool solve(vi& a,int n,int sum)
{
	bool dp[n+1][sum+1];

	rep(i,0,n)
	{
		rep(j,0,sum)
		{
			if(j==0)
				dp[i][j] = true;
			else if(i==0)
				dp[i][j] = false;

			else if(a[i-1]<=sum)
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];

			else
				dp[i][j] = dp[i-1][j];

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
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

