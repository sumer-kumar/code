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

int solve(int w[],int v[],int n,int W)
{
	int dp[n+1][W+1];

	rep(i,0,n)
	{
		rep(j,0,W)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(w[i-1]<=j)
				dp[i][j] = max(v[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][W];
}

int rodcutting(int a[],int n)
{
	int l[n];
	rep(i,0,n-1)
	l[i]=i+1;


	return solve(l,a,n,n);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    int a[n];
    rep(i,0,n-1)
    cin>>a[i];

   	cout<<rodcutting(a,n)<<endl;


	return 0;
}

