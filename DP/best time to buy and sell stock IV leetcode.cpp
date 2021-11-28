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
int dp[1001][101][2];
int recur(vi &a,int curr,int k,int state)
{

	if(curr==a.size() || k==0)
		return 0;

	if(dp[curr][k][state]!=-1)
		return dp[curr][k][state];

	if(state==0)
	{
		return dp[curr][k][state]=max(-a[curr]+recur(a,curr+1,k,!state),recur(a,curr+1,k,state));
	}
	/*state 1*/
	else
	{
		return dp[curr][k][state]=max(a[curr]+recur(a,curr+1,k-1,!state),recur(a,curr+1,k,state));
	}
}

int solve(vi &a,int k)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,k,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*	Input: k = 2, prices = [3,2,6,5,0,3]
		Output: 7*/
    /*Input: k = 2, prices = [2,4,1]
		Output: 2*/

    vi a = {3,2,6,5,0,3};
    int k=2;

    cout<<solve(a,k)<<endl;

	return 0;
}

