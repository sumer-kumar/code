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

/*same technique as LIS O(n^2)*/
int solve1(vi &a,int n)
{
	if(n==1)
		return 0;
	if(a[0]==0)
		return -1;

	vi dp(n,INT_MAX);
	dp[0]=1;

	rep(i,1,n-1)
	{
		rep(j,0,i-1)
		{
			if(a[j]+j>=i)
				dp[i]=min(dp[i],dp[j]+1);
		}
	}

	for(int x : dp)
		cout<<x<<" ";

	return dp[n-1]-1;
}

/*linear approach*/
int solve(vi &a,int n)
{
	if(n==1)
		return 0;
	if(a[0]==0)
		return -1;

	int maxReach = a[0];
	int stepsRemin = a[0];
	int jumps = 1;

	rep(i,1,n-2)
	{
		maxReach = max(maxReach,i+a[i]);
		stepsRemin--;
		if(stepsRemin==0)
		{	if(i>=maxReach)
			return -1;
			stepsRemin=maxReach-i;
			jumps++;
		}
		cout<<i<<" : "<<a[i]<<" "<<maxReach<<" "<<stepsRemin<<" "<<jumps<<endl;

	}	
	return jumps;
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

    cout<<solve(a,n)<<endl;


	return 0;
}

