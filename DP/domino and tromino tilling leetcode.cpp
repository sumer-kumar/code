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

#define TYPE_1 1
#define TYPE_2 2
#define TYPE_3 3

/*
	type 1 :
	 _ 
	| |
	|_|
	
	type 2 :
	 _ 
	|_|
	|
	
	type 3 :
	  
	|_
	|_|
*/

int dp[1001][4];
int recur(int curr,int type,int n)
{

	if(curr>n)
		return 0;

	if(curr==n)
	{
		if(type==TYPE_1)
			return 1;
		return 0;
	}

	if(dp[curr][type]!=-1)
		return dp[curr][type];

	if(type==TYPE_1)
	{
		int m1 = recur(curr+1,TYPE_1,n);
		int m2 = recur(curr+2,TYPE_2,n);
		int m3 = recur(curr+2,TYPE_3,n);
		int m4 = recur(curr+2,TYPE_1,n);

		return dp[curr][type]=(m1*1ll+m2*1ll+m3*1ll+m4*1ll)%mod;

	}
	else if(type==TYPE_2)
	{
		int m1 = recur(curr+1,TYPE_1,n);
		int m2 = recur(curr+1,TYPE_3,n);

		return dp[curr][type]=(m1*1ll+m2*1ll)%mod;
	}
	/*TYPE_3*/
	else 
	{
		int m1 = recur(curr+1,TYPE_1,n);
		int m2 = recur(curr+1,TYPE_2,n);

		return dp[curr][type]=(m1*1ll+m2*1ll)%mod;
	}
}

int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	return recur(0,TYPE_1,n)%mod;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=30;
    
    cout<<solve(n)<<endl;

	return 0;
}

