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
/*recursive approach*/
int pair_up(int n)
{	
	if(n==1||n==2||n==0)
		return n;
	return pair_up(n-1) + (n-1)*pair_up(n-2);
}


/*memoisation*/
vi lookup(1001,-1);
int pair_up2(int n)
{
	if(n==1||n==2||n==0)
		return n;

	if(lookup[n-1]==-1)
		lookup[n-1] = pair_up2(n-1);

	if(lookup[n-2]==-1)
		lookup[n-2] = pair_up2(n-2);

	lookup[n] = lookup[n-1]+(n-1)*lookup[n-2]; 
	return lookup[n];
}

/*tabulations*/
int pair_up3(int n)
{
	vi dp(n+1,-1);

	dp[0]=0;
	dp[1]=1;
	dp[2]=2;

	rep(i,3,n)
	{
		dp[i]=dp[i-1]+dp[i-2]*(i-1);
	}

	rep(i,0,n)
	cout<<i<<" : "<<dp[i]<<endl;

	return dp[n];
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	cout<<pair_up(n)<<endl;	
	cout<<pair_up2(n)<<endl;
	cout<<pair_up3(n)<<endl;

	rep(i,0,n)
	cout<<i<<" : "<<lookup[i]<<endl;	

	return 0;
}