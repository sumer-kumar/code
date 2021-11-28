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


int dp[201][201];
int recur(vvi &a,int i,int j)
{
	if(i>=a.size() || j>= a[0].size())
		return INT_MAX;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int health = min(recur(a,i+1,j),recur(a,i,j+1));

	if(health == INT_MAX)
		health = 1;

	int res = 0;
	
	if(health-a[i][j]>0)
		res = health-a[i][j];
	else
		res = 1;

	return dp[i][j]=res;
}

int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size();
	if(r==0)
		return 0;
	int c = a[0].size();
	return recur(a,0,0);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*	Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
	Output: 7*/

    vvi a = {
    	{-2,-3,3},
    	{-5,-10,1},
    	{10,30,-5}
    };

    cout<<solve(a)<<endl;

	return 0;
}

