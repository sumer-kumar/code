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

	the question is same as longest comman subsequence if you observe carefully

*/

int dp[555][555];
int recur(vi &a,vi &b,int aa,int bb)
{

	if(aa==0 || bb==0)
		return 0;

	if(dp[aa][bb]!=-1)
		return dp[aa][bb];

	if(a[aa-1]==b[bb-1])
	{
		return dp[aa][bb]=max(1+recur(a,b,aa-1,bb-1),max(recur(a,b,aa,bb-1),recur(a,b,aa-1,bb)));
	}

	return dp[aa][bb]=max(recur(a,b,aa,bb-1),recur(a,b,aa-1,bb));
}

int solve(vi &a,vi &b)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,b,a.size(),b.size());
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,5,1,2,5};
    vi b = {10,5,2,1,5,2};

    cout<<solve(a,b)<<endl;

	return 0;
}

