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
	player : 0 : player we wanted to win
	player : 1 : opposition
*/

int dp[100001][2];
bool recur(int n,int player)
{
	if(n==0)
		return player==0?false:true;
    
    if(dp[n][player]!=-1)
        return dp[n][player];
    
	if(player==0)
	{
		for(int i=1;i*i<=n;i++)
		{
			if(recur(n-i*i,!player)==true)
				return dp[n][player]=true;
		}
		return dp[n][player]=false;
	}
	else
	{
		for(int i=1;i*i<=n;i++)
		{
			if(recur(n-i*i,!player)==false)
				return dp[n][player]=false;
		}
		return dp[n][player]=true;
	}
}

int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	return recur(n,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=4;

    cout<<solve(n)<<endl;

	return 0;
}

