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


int dp[400][400];
int recur(vi &days,int curr,vi &cost,int day)
{

	if(curr>=days.size())
		return 0;

	if(dp[curr][day]!=-1)
		return dp[curr][day];

	if(days[curr]>=day)
	{
		/*01 day pass*/
		int m1 = cost[0]+recur(days,curr+1,cost,days[curr]+1);

		/*07 days pass*/
		int m2 = cost[1]+recur(days,curr+1,cost,days[curr]+7);

		/*30 days pass*/
		int m3 = cost[2]+recur(days,curr+1,cost,days[curr]+30);

		return dp[curr][day] = min(m1,min(m2,m3));
	}

	return dp[curr][day] = recur(days,curr+1,cost,day);
}

int solve(vi &days,vi &cost)
{
	memset(dp,-1,sizeof(dp));
	int t = recur(days,0,cost,1);

	return t;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi days = {1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
    vi cost = {3,13,45};

    cout<<solve(days,cost)<<endl;

	return 0;
}

