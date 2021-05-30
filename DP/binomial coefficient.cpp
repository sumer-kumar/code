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

int recur(int n,int r)
{
	if(r>n)
		return 0;

	if(r==0||r==n)
		return 1;

	return recur(n-1,r-1)+recur(n-1,r);
}


int solve(int n,int r)
{
	int dp[n+1][n+2]={0};
	rep(i,0,n)/*n*/
	{
		rep(j,0,n)/*r*/
		{
			if(i<j)
				dp[i][j]=0;
			else if(j==0||i==j)
				dp[i][j]=1;
			else
				dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	return dp[n][r];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin>>n>>r;

    cout<<recur(n,r)<<endl;
    cout<<solve(n,r)<<endl;

	return 0;
}

