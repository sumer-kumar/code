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


int dp[111][111];

int recur(vvi &a,int r,int c)
{

	if(r<0 || c<0)
		return 0;

	if(r==0 || c==0)
	{
		return a[r][c]!=1;		
	}

	if(dp[r][c]!=-1)
		return dp[r][c];

	if(a[r][c]!=1)
	{
		return dp[r][c]= recur(a,r-1,c)+recur(a,r,c-1);
	}

	return dp[r][c]=0;
}


int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size();
	int c = a[0].size();

	bool f=false;
	for(int i=0;i<r;i++)
	{	
		if(a[i][0]==1)
		{
			f=true;
		}
		if(f)
		{
			a[i][0]=1;
		}
	}

	f=false;
	for(int i=0;i<c;i++)
	{	
		if(a[0][i]==1)
		{
			f=true;
		}
		if(f)
		{
			a[0][i]=1;
		}
	}

	// for(auto x : a)
	// {
	// 	for(int p : x)
	// 		cout<<p<<" ";
	// 	cout<<endl;
	// }

	return recur(a,r-1,c-1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi a = {
    	// {0,0,0},
    	// {0,1,0},
    	// {0,0,0}

    	// {0,1},
    	// {0,0}

    	{1,0}
    };

    cout<<solve(a)<<endl;

	return 0;
}

