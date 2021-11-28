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

int dp[40][40*100];
int recur(vi &a,int n,int half_sum)
{
	if(n<=0 || half_sum==0)
		return 0;

	if(dp[n][half_sum]!=-1)
		return dp[n][half_sum];

	if(half_sum-a[n-1]>=0)
	{
		return dp[n][half_sum] = max(a[n-1]+recur(a,n-1,half_sum-a[n-1]),recur(a,n-1,half_sum));
	}

	return dp[n][half_sum] = recur(a,n-1,half_sum);
}

int solve(vi &a)
{

	memset(dp,-1,sizeof(dp));
	int sum = 0;
	for(int x : a )
	sum += x;

	return sum - 2*recur(a,a.size(),sum/2);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {31,26,33,21,40};

    cout<<solve(a)<<endl;

	return 0;
}

