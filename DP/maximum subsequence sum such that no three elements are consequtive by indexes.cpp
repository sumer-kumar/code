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
int recur(vi& a,int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return a[0];
	if(n==2)
		return a[0]+a[1];

	int ex2 = recur(a,n-1);
	int ex1 = recur(a,n-2)+a[n-1];
	int ex0 = recur(a,n-3)+a[n-1]+a[n-2];

	return max(ex2,max(ex1,ex0));
}

/*bottom up approach*/
int solve(vi &a,int n)
{
	vi dp(n+1,0);
	dp[1]=a[0];
	dp[2]=a[0]+a[1];

	rep(i,3,n)
	{
		int ex3 = dp[i-1];
		int ex2 = dp[i-2]+a[i-1];
		int ex1 = dp[i-3]+a[i-1]+a[i-2];
		dp[i] = max(ex1,max(ex2,ex3)); 
	}
	return dp[n];
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

    cout<<recur(a,n)<<endl;
    cout<<solve(a,n)<<endl;

	return 0;
}

