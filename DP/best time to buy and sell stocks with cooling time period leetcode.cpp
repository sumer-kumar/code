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

/*
	state 0 : buy
	state 1 : sell
*/


int dp[5555][2];
int recur(vi &a,int curr,int state)
{

	if(curr>=a.size())
		return 0;

	if(dp[curr][state]!=-1)
		return dp[curr][state];

	if(state==0) /*buy*/
	{	
		return dp[curr][state] = max(recur(a,curr+1,1) - a[curr],recur(a,curr+1,0));
	}
	else /*sell*/
	{
		return dp[curr][state] = max(a[curr]+recur(a,curr+2,0),recur(a,curr+1,1));
	}
}


int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));

	return recur(a,0,0)<0 ? 0 : recur(a,0,0);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,1,4};

    cout<<solve(a)<<endl;

	return 0;
}

