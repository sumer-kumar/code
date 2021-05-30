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

/*recursive*/
int recur(int f,int e)
{
	/*base conditions*/
	if(f==0||f==1)
		return f;
	if(e==1)
		return f;

	int ans=INT_MAX;
	for(int i=1;i<=f;i++)
	{
		int breaks = recur(f-i,e-1);
		int notBreaks = recur(i-1,e);

		int worst = max(breaks,notBreaks);
		ans = min(ans,worst);
	}
	return ans+1;
}

/*memoization*/
int dp[1001][1001];
int memo(int f,int e)
{
	/*base conditions*/
	if(f==0||f==1)
		return f;
	if(e==1)
		return f;

	if(dp[f][e]!=-1)
		return dp[f][e];

	int ans=INT_MAX;
	for(int i=1;i<=f;i++)
	{
		int breaks,notBreaks;

		if(dp[f-i][e-1]!=-1)
			breaks = dp[f-i][e-1];
		else
			breaks = recur(f-i,e-1);
		
		if(dp[i-1][e]!=-1)
			notBreaks = dp[i-1][e];
		else
			notBreaks = recur(i-1,e);

		int worst = max(breaks,notBreaks);
		ans = min(ans,worst);
	}
	return dp[f][e] = ans+1;
}




/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e,f;
    cin>>f>>e;
    memset(dp,-1,sizeof(dp));
    cout<<recur(f,e)<<endl;
    cout<<memo(f,e)<<endl;


	return 0;
}

