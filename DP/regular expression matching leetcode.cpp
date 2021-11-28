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
int dp[21][31];
int recur(string &s,string &p,int ss,int pp)
{

	if(ss<0 && pp<0)
		return true;

	if(pp<0)
		return false;

	if(ss<0)
	{
		if(p[pp]=='*')
			return recur(s,p,ss,pp-2);
		return false;
	}

	if(dp[ss][pp]!=-1)
		return dp[ss][pp];

	if(s[ss]==p[pp])
		return dp[ss][pp]=recur(s,p,ss-1,pp-1);
	if(p[pp]=='.')
		return dp[ss][pp]=recur(s,p,ss-1,pp-1);
	if(p[pp]=='*')
	{
		/* star and start preceeding character are repeated 0 times */
		if(recur(s,p,ss,pp-2))
			return dp[ss][pp]=true;

		/*check for previous character in the pattern and check and remove start*/
		if( (p[pp-1]=='.' || p[pp-1]==s[ss]) && 
		  ( recur(s,p,ss-1,pp) || recur(s,p,ss-1,pp-2)))
			return dp[ss][pp]=true;
	}

	return dp[ss][pp]=false;
}

int solve(string &s,string &p)
{
	memset(dp,-1,sizeof(dp));

	int ss = s.size();
	int pp = p.size();

	return recur(s,p,ss-1,pp-1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    "aab"
	"c*a*b"
	*/
	/*
	"aaa"
	"ab*a*c*a"
	*/

    string s = "aab";
    string p = "c*a*b";

    cout<<solve(s,p)<<endl;

	return 0;
}

