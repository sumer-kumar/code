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

int dp[1001][1001];
int recur(int n,int k)
{
	if(n==0)
		return 0;
	if(k==0)
		return 1;

	if(dp[n][k]!=-1)
		return dp[n][k];

	int res = 0;
	rep(i,0,min(n-1,k))
	{
		res = res + recur(n-1,k-i);
	}

	return dp[n][k]=res;
}

int solve(int n,int k)
{
	memset(dp,-1,sizeof(dp));
	return recur(n,k);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    int k = 1;

    cout<<solve(n,k)<<endl;

	return 0;
}

