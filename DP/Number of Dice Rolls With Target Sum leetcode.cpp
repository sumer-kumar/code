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
int dp[31][1001];
int recur(int d,int f,int target)
{
	if(d==0)
	{
		if(target==0)
			return 1;
		return 0;
	}

	if(dp[d][target]!=-1)
		return dp[d][target];

	int tt=0;
	rep(i,1,f)
	{
		if(target-i>=0)
		{
			tt = ((ll)tt + (ll)recur(d-1,f,target-i))%mod;
		}
		else
			break;
	}

	return dp[d][target] = tt;
}

int solve(int d,int f,int target)
{
	memset(dp,-1,sizeof(dp));
	return recur(d,f,target);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*d = 1, f = 6, target = 3*/
    int d = 30;
    int f = 30;
    int target = 500;

    cout<<solve(d,f,target);

	return 0;
}

