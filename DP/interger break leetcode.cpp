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

int dp[100];
int recur(int n)
{

	if(n==1||n==2)
		return 1;

	if(dp[n]!=-1)
		return dp[n];

	int res = 0;

	rep(i,1,n-1)
	{
		res = max(res,i*max(recur(n-i),n-i));
	}
	// cout<<n<<" "<<res<<endl;

	return dp[n] = res;
}


int solve(int n)
{

	memset(dp,-1,sizeof(dp));
	if(n<1)
		return 0;

	return recur(n);
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 10;

    cout<<solve(n)<<endl;


	return 0;
}

