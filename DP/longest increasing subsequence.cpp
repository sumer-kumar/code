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

/*dp O(n^2)*/
int solve1(vi& a,int n)
{
	vi dp(n+1,1);
	int ans = 1;

	rep(i,1,n)
	{
		rep(j,0,i-1)
		{
			if(a[j]<a[i])
			{
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
				ans = max(ans,dp[i]);
	}

	for(auto x : dp)
		cout<<x<<" ";

	return ans;
}

/*dp + binary search O(nlogn)*/
int solve(vi& a,int n)
{
	vi dp;
	dp.pb(a[0]);

	rep(i,1,n-1)
	{
		if(a[i]>dp.back())
			dp.pb(a[i]);
		else
		{
			int ind = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
			dp[ind] = a[i];
		}
	}
	return dp.size();
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

    cout<<solve1(a,n)<<endl;

	return 0;
}

