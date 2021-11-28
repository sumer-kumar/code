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
	state 0 : alice turn : our player
	state 1 : bob turn : enemy
*/
// int dp[curr][m][state];
int dp[111][111][2];
int recur(vi &a,int curr,int m,int state)
{
	int size = a.size();

	if(curr>=size)
		return 0;

	if(dp[curr][m][state]!=-1)
		return dp[curr][m][state];

	if(state==0)
	{
		int res = 0;
		int sum = 0;
		int k = 0;
		for(int i=curr;i<size && i<curr+2*m;i++)
		{
			k++;
			sum += a[i];
			res = max(res, sum + recur(a,i+1,max(m,k),!state));
		}
		return dp[curr][m][state] = res;
	}
	else
	{	
		/*opponents turn*/
		int res = INT_MAX;
		int k = 0;
		for(int i=curr;i<size && i<curr+2*m;i++)
		{
			k++;
			res = min(res, recur(a,i+1,max(m,k),!state));
		}

		return dp[curr][m][state] = res;
	}
}

int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,1,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*ans : 104*/
    vi a = {1,2,3,4,5,100};

    cout<<solve(a)<<endl;

	return 0;
}

