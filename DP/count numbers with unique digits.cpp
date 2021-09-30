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

vi dp(11,-1);
int recur(int n)
{

	if(n==1)
		return 10;

	if(dp[n]!=-1)
		return 9*dp[n];

	int res = 1;
	int curr = 9;

	while(--n)
	{
		if(dp[n+1]!=-1)
			return 9*dp[n+1];
		
		res *= curr;
		curr--;
	}

	dp[n] = res;

	return 9*res;
}

int solve(int n)
{
	if(n==0)
		return 1;

	int res = 0;

	rep(i,1,n)
	{
		res += recur(i);
	}	

	return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=3;

    cout<<solve(n)<<endl;

	return 0;
}

