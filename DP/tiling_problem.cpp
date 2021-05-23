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

int fun(int n)
{
	vi dp(n+1);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;

	rep(i,3,n)
	{
		dp[i] = dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;	

	cout<<fun(n)<<endl;

	return 0;
}