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

/*recursive*/
int recur(int n,int x,int y,int z)
{

	if(n==0)
		return 0;

	int p,q,r;
	p = q = r = INT_MIN;


	if(n-x>=0)
		p=recur(n-x,x,y,z);
	if(n-y>=0)
		q=recur(n-y,x,y,z);
	if(n-z>=0)
		r=recur(n-z,x,y,z);

	return max(p,max(q,r))+1;
}

/*dp*/
int solve(int n,int x,int y,int z)
{
	vi dp(n+1,0);

	rep(i,1,n)
	{
		int p,q,r;
		p = q = r = INT_MIN;

		if(i-x>=0)
			p=dp[i-x];
		if(i-y>=0)
			q=dp[i-y];
		if(i-z>=0)
			r=dp[i-z];
		dp[i] = max(p,max(q,r))+1;
	}
	return dp[n]==INT_MIN?0:dp[n];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y,z;
    cin>>n>>x>>y>>z;

    cout<<recur(n,x,y,z)<<endl;
    cout<<solve(n,x,y,z)<<endl;
    cout<<INT_MIN<<endl;

	return 0;
}

