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


bool dpsol(vi &a,int n,int sum)
{
	int dp[n+1][sum+1];

	rep(i,0,n)
	{
		rep(j,0,sum)
		{
			if(j==0)
				dp[i][j] = true;
			else if(i==0)
				dp[i][j] = false;
			else if(a[i-1]<=j)
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}


bool solve(vi &a,int n)
{
	int sum = 0;
	rep(i,0,n-1)
	sum+=a[i];

	if(sum&1) return false;
	// cout<<sum<<endl;
	return dpsol(a,n,sum/2);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,5,11,5};

    cout<<solve(a,a.size())<<endl;

	return 0;
}

