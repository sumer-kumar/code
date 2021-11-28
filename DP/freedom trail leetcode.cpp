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
	state : 0 : rotating clock wise : increasing index
	state : 1 : rotating anticlock wise : decreasing index
*/
int dp[101][101][2];
int recur(string &ring,string &key,int r,int k,int state)
{
	int rr = ring.size();
	int kk = key.size();

	if(k==kk)
		return 0;

	if(dp[r][k][state]!=-1)
		return dp[r][k][state];

	if(ring[r]==key[k])
	{
		return dp[r][k][state]=1 + min(recur(ring,key,r,k+1,0),recur(ring,key,r,k+1,1));
	}

	if(state==0)
	{
		return dp[r][k][state]=1+recur(ring,key,(r+1)%rr,k,state);
	}
	/*state 1 */
	else
	{
		int ind = r==0?rr-1:r-1;
		return dp[r][k][state]=1 + recur(ring,key,ind,k,state);
	}
}

int solve(string &ring,string &key)
{
	memset(dp,-1,sizeof(dp));
	return min(recur(ring,key,0,0,0),recur(ring,key,0,0,1));
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*	Input: ring = "godding", key = "gd"
		Output: 4*/

    string ring = "godding";
    string key = "godding";

    cout<<solve(ring,key)<<endl;

	return 0;
}

