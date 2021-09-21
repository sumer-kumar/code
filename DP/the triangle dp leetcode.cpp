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

int dp[222][222];
int recur(vvi &a,int r,int c,int size)
{

	if(r>=size)
		return 0;

	if(dp[r][c]!=-1)
		return dp[r][c];

	return dp[r][c] = a[r][c] + min(recur(a,r+1,c,size),recur(a,r+1,c+1,size));
}

int bu(vvi &a)
{

	int r = a.size();

	vvi dp(3,vector<int>(r+2,0));

	for(int i=r-1;i>=0;i--)
	{
		for(int j=a[i].size()-1;j>=0;j--)
		{
			dp[i%2][j] = a[i][j] + min(dp[(i+1)%2][j],dp[(i+1)%2][j+1]);
		}
	}

	return dp[0][0];

}

int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r=0;
	int c=0;
	int size = a.size();

	return recur(a,r,c,size);
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// [[2],[3,4],[6,5,7],[4,1,8,3]]
    vvi a = {
    	{2},
    	{3,4},
    	{6,5,7},
    	{4,1,8,3},
    };

    cout<<solve(a)<<endl;
    cout<<bu(a)<<endl;

	return 0;
}


