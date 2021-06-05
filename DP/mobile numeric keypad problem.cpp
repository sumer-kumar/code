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


ll recur(vector<vector<char>> &pad,ll i,ll j,ll n)
{
	if(i<0 || i>3 || j<0 || j>2)
		return 0;
	if(pad[i][j]=='*'||pad[i][j]=='#')
		return 0;


	if(n==0)
		return 1;

	ll m1,m2,m3,m4,m5;
	m1=m2=m3=m4=m5=0;

		m5 = recur(pad,i,j,n-1);

	// if(i-1>=0)
		m1 = recur(pad,i-1,j,n-1);
	// if(i+1<=0)
		m2 = recur(pad,i+1,j,n-1);
	// if(j-1>=0)
		m3 = recur(pad,i,j-1,n-1);
	// if(j+1<=0)
		m4 = recur(pad,i,j+1,n-1);

	return m1+m2+m3+m4+m5;
}

int dp[5][4][26];
ll memo(vector<vector<char>> &pad,ll i,ll j,ll n)
{
	if(i<0 || i>3 || j<0 || j>2)
		return 0;

	if(dp[i][j][n]!=-1)
		return dp[i][j][n];

	if(pad[i][j]=='*'||pad[i][j]=='#')
		return dp[i][j][n]=0;


	if(n==0)
		return dp[i][j][n]=1;

	ll m1,m2,m3,m4,m5;
	m1=m2=m3=m4=m5=0;

	if(dp[i-1][j][n-1]!=-1)
		m1 = dp[i-1][j][n-1];
	else
		dp[i-1][j][n-1]=m1 = memo(pad,i-1,j,n-1);
	
	
	if(dp[i+1][j][n-1]!=-1)
		m2 = dp[i+1][j][n-1];
	else
		dp[i+1][j][n-1] =m2 = memo(pad,i+1,j,n-1);

	
	if(dp[i][j-1][n-1]!=-1)
		m3 = dp[i][j-1][n-1];
	else
	dp[i][j-1][n-1] = m3 = memo(pad,i,j-1,n-1);

	
	if(dp[i][j+1][n-1]!=-1)
		m4 = dp[i][j+1][n-1];
	else
		dp[i][j+1][n-1] = m4 = memo(pad,i,j+1,n-1);


	m5 = memo(pad,i,j,n-1);

	return m1+m2+m3+m4+m5;

}

ll recurFun(vector<vector<char>> &pad,ll n)
{
	ll ans = 0;
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<=3;i++)
	{
		for(ll j=0;j<=2;j++)
		{
			if(pad[i][j]=='*'||pad[i][j]=='#')
				continue;
			ans += memo(pad,i,j,n-1);
		}
	}

	return ans;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;

    vector<vector<char>> pad = {{'1','2','3'},
								{'4','5','6'},
								{'7','8','9'},
								{'*','0','#'}};

	cout<<recurFun(pad,n)<<endl;


	return 0;
}

