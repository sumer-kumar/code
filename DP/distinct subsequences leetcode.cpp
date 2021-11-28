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
	note : we have to delete characters from string "s"
*/
int dp[1001][1001];
int recur(string &s,string &t,int ss,int tt)
{

	if(ss==0 && tt==0)
		return 1;
	if(ss==0)
		return 0;
	if(tt==0)
		return recur(s,t,ss-1,tt);

	if(dp[ss][tt]!=-1)
		return dp[ss][tt];

	if(s[ss-1]==t[tt-1])
		return dp[ss][tt]=recur(s,t,ss-1,tt-1) + recur(s,t,ss-1,tt);
	return dp[ss][tt]=recur(s,t,ss-1,tt);
}

int solve(string &s,string &t)
{
	memset(dp,-1,sizeof(dp));
	int ss = s.size();
	int tt = t.size();

	return recur(s,t,ss,tt);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*s = "rabbbit", t = "rabbit"*/
    /*s = "babgbag", t = "bag"*/
    string s = "babgbag";
    string t = "bag";

    cout<<solve(s,t)<<endl;

	return 0;
}

