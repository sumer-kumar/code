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

int recur(int n)
{
	if(n<=1)
		return 1;

	int res = 0;
	for(int i=0;i<n;i++)
	{
		res = res + recur(n-i-1)*recur(i);
	}
	return res;
}


int solve(int n)
{
	vi dp(n+1,0);

	dp[0]=1;
	dp[1]=1;


	rep(i,2,n)
	{
		rep(j,0,i-1)
		{
			dp[i] += (dp[i-j-1]*dp[j]);
		}
		// cout<<dp[i]<<" ";
	}

	return dp[n];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<recur(n)<<endl;
    cout<<solve(n)<<endl;

	return 0;
}

