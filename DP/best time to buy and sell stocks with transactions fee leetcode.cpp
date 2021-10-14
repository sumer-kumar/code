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
	state : 0 : buying
	state : 1 : selling
*/

int dp[11111][2];
int recur(vi &a,int curr,int state,int fee)
{


	if(curr>=a.size())
		return 0;
	if(dp[curr][state]!=-1)
		return dp[curr][state];

	/*buying state*/
	if(state==0)
	{
		/*max of buying and not buying*/
		return dp[curr][state] = max(-a[curr]+recur(a,curr+1,!state,fee),recur(a,curr+1,state,fee));
	}
	/*selling state*/
	else
	{
		/*max of selling and not sellilng*/
		return dp[curr][state]=max(a[curr] -fee +recur(a,curr+1,!state,fee),recur(a,curr+1,state,fee));
	}
}

int solve(vi &a,int fee)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,0,fee);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,3,7,5,10,3};
    int fee = 3;

    cout<<solve(a,fee)<<endl;

	return 0;
}

