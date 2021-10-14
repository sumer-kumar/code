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

int dp[1000][1000];
int recur(int curr,int last,int n)
{
	if(curr==n)
		return 0;
	if(curr>n)
		return 100000;

	if(dp[curr][last]!=-1)
		return dp[curr][last];

	/*then do not copy but paste*/
	if(curr==last)
	{
		return dp[curr][last] =1 + recur(curr+last,last,n);
	}
	/*copy and paste*/
	else
	{
		int cp = 1+recur(curr,curr,n);
		int pst = 1+recur(curr+last,last,n);
		return dp[curr][last]=min(cp,pst);
	}
}

int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	if(n==1)
		return 0;
	return 1+recur(1,1,n);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 10;

    cout<<solve(n)<<endl;

	return 0;
}

