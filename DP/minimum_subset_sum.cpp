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
int recur(vi& a,int n,int range,int sum=0)
{
	if(n==0)
		return range - 2*sum;

	if(range/2 >= sum + a[n-1])
	{
		return min(recur(a,n-1,range,sum+a[n-1]),recur(a,n-1,range,sum));
	}
	return recur(a,n-1,range,sum);
}

int recur2(vi& a,int n,int sum)
{
	if(n==0)
		return sum;

	if(a[n-1]<=sum)
	{
		return min(recur2(a,n-1,sum-a[n-1]),recur2(a,n-1,sum));
	}
	return recur2(a,n-1,sum);
}

int rfun(vi &a,int n)
{
	int sum = 0;
	rep(i,0,n-1)
	sum+=a[i];
	int m1 = recur2(a,n,sum/2);

	return sum - 2*(sum/2-m1);
}

/*using bottom up approach the real dp*/
int solve(vi& a,int n)
{
	int sum =0;
	rep(i,0,n-1)
	sum+=a[i];

	int range = sum/2;
	int dp[n+1][range+1];


	rep(i,0,n)
	{	
		rep(j,0,range)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=0;
			else if(a[i-1]<=j)
				dp[i][j]=min(dp[i-1][j-a[i-1]],dp[i-1][j]);
			else 
				dp[i][j]=dp[i-1][j];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return sum - 2*(range-dp[n][range]);
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

    // cout<<rfun(a,n)<<endl;
    cout<<solve(a,n)<<endl;

	return 0;
}

