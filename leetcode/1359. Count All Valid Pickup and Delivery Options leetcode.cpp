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


int dp[501][501];
int recur(int p,int d)
{	
	if(p==0 && d==0)
		return 1;

	if(p<0 || d<0 || p>d)
		return 0;

	if(dp[p][d]!=-1)
		return dp[p][d];

	long long res = 0;

	res = (res + 1ll*p*recur(p-1,d))%mod;

	res = (res + 1ll*(d-p)*recur(p,d-1))%mod;

	return dp[p][d] = res;
}

int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	return recur(n,n);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=90;

    cout<<solve(n)<<endl;

	return 0;
}

