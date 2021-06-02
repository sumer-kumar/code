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

/*recursive approach assuming array is already sorted*/
int recur(vi &a,int n,int k)
{
	if(n<=1)
		return 0;

	if(abs(a[n-1]-a[n-2])<k)
	{
		return max(recur(a,n-2,k)+a[n-1]+a[n-2],recur(a,n-1,k));
	}
	return recur(a,n-1,k);
}

/*bottom up*/
int solve(vi &a,int n,int k)
{
	vi dp(n+1);

	rep(i,0,n)
	{
		if(i<=1)
			dp[i]=0;
		else if(abs(a[i-1]-a[i-2])<k)
			dp[i]=max(dp[i-2]+a[i-1]+a[i-2],dp[i-1]);
		else 
			dp[i]=dp[i-1];
	}

	return dp[n];
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

    sort(a.begin(),a.end());

	cout<<recur(a,n,k)<<endl;    
	cout<<solve(a,n,k)<<endl;    

	return 0;
}

