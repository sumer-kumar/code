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


int dp[111];
int recur(vi &a,int n)
{
	if(n<=0)
		return 0;

	if(dp[n]!=-1)
		return dp[n];

	return dp[n] = max(a[n-1] + recur(a,n-2),recur(a,n-1));
}

int solve(vi a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();

	if(size==1)
		return a[0];

	int res = recur(a,size-1);
	reverse(a.begin(),a.end());

	memset(dp,-1,sizeof(dp));
	res = max(res,recur(a,size-1));

	return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,2,3};

    cout<<solve(a)<<endl;

	return 0;
}

