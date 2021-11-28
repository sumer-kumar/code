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

/*
	we can minimize space and time complexity because we can always calculate j2 
	with the help of i1 j1 i2 by 
	j2 = i1 + j2 - i2;

*/

int dp[51][51][51][51];
int recur(vvi &a,int i1,int j1,int i2,int j2,int n)
{

	if(i1<0 || i1>=n || j1<0 || j1>=n || a[i1][j1]==-1)
		return INT_MIN;

	if(i2<0 || i2>=n || j2<0 || j2>=n || a[i2][j2]==-1)
		return INT_MIN;

	if(dp[i1][j1][i2][j2]!=-1)
		return dp[i1][j1][i2][j2];

	if(i1==n-1 && j1==n-1)
		return a[i1][j1];

	int res = 0;
	if(i1==i2 && j1==j2)
	{
		res += a[i1][j1];
	}
	else 
	{
		res += a[i1][j1]+a[i2][j2];
	}

	int m1 = recur(a,i1,j1+1,i2,j2+1,n);
	int m2 = recur(a,i1+1,j1,i2+1,j2,n);
	int m3 = recur(a,i1,j1+1,i2+1,j2,n);
	int m4 = recur(a,i1+1,j1,i2,j2+1,n);

	return dp[i1][j1][i2][j2] = res + max({m1,m2,m3,m4});
}

int solve(vvi &a)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,0,0,0,a.size());
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi a = {
    	{0,1,-1},
    	{1,0,-1},
    	{1,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

