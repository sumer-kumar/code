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

int recur(vvi& a,int i,int n,int j)
{
	if(j==0)
		return a[i][j];

	int up,down,h;
	up=down=h=0;
	if(i-1>=0 && j-1>=0)
		up = recur(a,i-1,n,j-1);

	if(j-1>=0)
		h = recur(a,i,n,j-1);

	if(i+1<n && j-1>=0)
		down = recur(a,i+1,n,j-1);

	int ans = max(h,max(up,down))+a[i][j];
	
	return ans;
}

int recurFun(vvi& a,int n,int m)
{
	int ans = INT_MIN;
	rep(i,0,n-1)
	{
		ans = max(ans,recur(a,i,n,m-1));
	}
	return ans;
}

/*bottom up*/
int solve(vvi &a,int n,int m)
{
	int dp[n+1][m+1]={0};
	rep(j,0,m-1)
	{
		rep(i,0,n-1)
		{
			if(j==0)
				dp[i][j]=a[i][j];

			else
			{
				int u,d,h;
				u=d=h=0;
				if(i-1>=0)
					u = dp[i-1][j-1];

				h = dp[i][j-1];

				if(i+1<n)
					d = dp[i+1][j-1];

				dp[i][j] = max(h,max(u,d))+a[i][j];
			}
		}
	}

	int ans = INT_MIN;
	rep(i,0,n-1)
	ans=max(dp[i][m-1],ans);
	
	return ans;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));

    rep(i,0,n-1)
    	rep(j,0,m-1)
    	cin>>a[i][j];

    cout<<recurFun(a,n,m)<<endl;
    cout<<solve(a,n,m)<<endl;


	return 0;
}

