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

int dp[1001][1001];
int recur(vi &a,vi &b,int aa,int bb,int count)
{

	if(aa==0 || bb==0)
		return count;

	if(dp[aa][bb]!=-1)
		return dp[aa][bb];

	if(a[aa-1]==b[bb-1])
	{
		int t = recur(a,b,aa-1,bb-1,count+1);
		return dp[aa][bb] = max(count,t);
	}

	return dp[aa][bb] = max(recur(a,b,aa,bb-1,0),recur(a,b,aa-1,bb,0));
}

int solve2(vi &a,vi &b)
{
	int aa = a.size();
	int bb = b.size();

	int dp[3][bb+1];
	memset(dp,0,sizeof(dp));

	int mx = 0;

	rep(i,0,aa)
	{
		rep(j,0,bb)
		{
			if(i==0 || j==0)
				continue;
			if(a[i-1]==b[j-1])
			{
				dp[i%2][j]=dp[(i-1)%2][j-1]+1;
				mx=max(mx,dp[i%2][j]);
			}
			else
				dp[i%2][j]=0;
		}
	}
	return mx;
}

int solve(vi &a,vi &b)
{
	memset(dp,-1,sizeof(dp));
	int aa = a.size();
	int bb = b.size();

	int t = recur(a,b,aa,bb,0);

    rep(i,0,aa)
    {
        rep(j,0,bb)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

	return t;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
		[1,0,0,0,1,0,0,1,0,0]
		[0,1,1,1,0,1,1,1,0,0]
*/

    vi a = {1,0,0,0,1,0,0,1,0,0};
    vi b = {0,1,1,1,0,1,1,1,0,0};

    cout<<solve2(a,b)<<endl;

	return 0;
}

