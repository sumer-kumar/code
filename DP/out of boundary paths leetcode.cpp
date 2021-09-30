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

int dp[100][100][100];
int recur(int i,int j,int n,int m,int k)
{

	if(i<0 || i>=n || j<0 || j>=m)
		return 1;

	if(dp[i][j][k]!=-1)
		return dp[i][j][k];

	if(k==0)
		return 0;

	int res = 0;

	res = (res + recur(i+1,j,n,m,k-1)%mod)%mod;
	res = (res + recur(i,j+1,n,m,k-1)%mod)%mod;
	res = (res + recur(i-1,j,n,m,k-1)%mod)%mod;
	res = (res + recur(i,j-1,n,m,k-1)%mod)%mod;

	return dp[i][j][k]=res;
}

int solve(int i,int j,int n,int m,int k)
{
	memset(dp,-1,sizeof(dp));
	return recur(i,j,n,m,k);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,i,j,k;
/* m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0*/
/*m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1*/
/*
8
50
23
5
26

*/

    n=8;
    m=50;
    k=23;
    i=5;
    j=26;

    cout<<solve(i,j,n,m,k)<<endl;

	return 0;
}

