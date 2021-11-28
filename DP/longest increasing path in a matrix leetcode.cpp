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

vvi d = {
	{1,0},
	{-1,0},
	{0,-1},
	{0,1}
};

int dp[201][201];
int recur(vvi &a,int i,int j,int r,int c)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	int res = 0;
	/*choose the directions*/
	for(auto dir : d)
	{
		int x = i + dir[0];
		int y = j + dir[1];
		if(x<r && x>=0 && y<c && y>=0 && a[x][y]>a[i][j])
			res = max(res,1+recur(a,x,y,r,c));
	}
	return dp[i][j]=res;
}

int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size();
	int c = a[0].size();

	int res = 0;

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			res = max(res,1+recur(a,i,j,r,c));
		}
	}
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
		Output: 4*/

    vvi a = {
    	{9,9,4},
    	{6,6,8},
    	{2,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

