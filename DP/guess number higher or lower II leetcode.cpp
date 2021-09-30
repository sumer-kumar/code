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


int dp[222][222];
int recur(int start,int end)
{

	if(end<start)
		return -1;

	if(dp[start][end]!=-1)
		return dp[start][end];

	if(start+2==end)
		return dp[start][end]=start+1;

	if(start+1==end)
		return dp[start][end]=start;

	if(start==end)
		return dp[start][end]=0;

	int res = INT_MAX;
	
	rep(i,start,end)
	{
		int t = i+max(recur(start,i-1),recur(i+1,end));

		res = min(res,t);
	}
	// cout<<start<<" "<<end<<" "<<res<<endl;

	return dp[start][end]=res;
}


int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	return recur(1,n);
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

