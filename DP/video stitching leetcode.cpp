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
//static
bool cmp(const vi &a,const vi &b)
{
	return a[0]<b[0];
}

int dp[111][111];
int recur(vvi &a,int curr,int max_i,int time)
{

	if(curr>=a.size())
	{
		//if reached to time 
		if(max_i>=time)
			return 0;
		return 100000;
	}

	if(dp[curr][max_i]!=-1)
		return dp[curr][max_i];

	if( max_i >= a[curr][0] && max_i < a[curr][1] )
	{
		int m1 = 1 + recur(a,curr+1,max(max_i,a[curr][1]),time);
		int m2 = recur(a,curr+1,max_i,time);

		return dp[curr][max_i] = min(m1,m2);
	}

	return dp[curr][max_i] = recur(a,curr+1,max_i,time);
}

int solve(vvi &a,int time)
{

	memset(dp,-1,sizeof(dp));

	//sort w.r.t starting point
	sort(a.begin(),a.end(),cmp);

	int t = recur(a,0,0,time);

	return t>=100000?-1:t;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]*/

    vvi a = {
    	{0,2},
    	{4,6},
    	{8,10},
    	{1,9},
    	{1,5},
    	{5,9}
    	// {0,1},
    	// {1,2}
    };

	int time = 10;

    cout<<solve(a,time)<<endl;

	return 0;
}

