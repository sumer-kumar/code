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

int dp[1000][10000];
int recur(string &a,int curr,int tt)
{

	if(tt<0)
		return false;

	if(curr==a.size())
	{
		if(tt==0)
			return true;
		return false;
	}

	if(dp[curr][100+tt]!=-1)
		return dp[curr][100+tt];

	if(a[curr]=='(')
		return dp[curr][100+tt]=recur(a,curr+1,tt+1);
	if(a[curr]==')')
		return dp[curr][100+tt]=recur(a,curr+1,tt-1);

	return dp[curr][100+tt]=recur(a,curr+1,tt-1) || recur(a,curr+1,tt+1) || recur(a,curr+1,tt);

}

bool solve(string &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();
	return recur(a,0,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "*****)";

    cout<<solve(a)<<endl;

	return 0;
}

