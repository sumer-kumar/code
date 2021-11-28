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

MEMOIZATION WORKING BUT IT STILL EXPONENTIAL CAUSE WE CANNOT MEMOIZE 
RETURNING PATH AS ITS GRID KEPT CHANGIN

*/


int dp1[51][51];

int recur2(vvi &a,int i,int j,int r,int c)
{

	if(i==0 && j==0)
		return 0;

	if(i<0 || i>=r || j<0 || j>=c)
		return INT_MIN;

	if(a[i][j]==0)
	{
		return max(recur2(a,i-1,j,r,c),recur2(a,i,j-1,r,c));
	}
	else if(a[i][j]==1)
	{
		int m1 = 1+recur2(a,i-1,j,r,c);
		int m2 = 1+recur2(a,i,j-1,r,c);

		return max(m1,m2);
	}
	/* a[i][j]==-1 */
	return INT_MIN;
}


/*going to target phase*/
int recur(vvi &a,int i,int j,int r,int c)
{

	if(i==r-1 && j==c-1)
	{
		/*returning from target to origin phase*/
		return recur2(a,i,j,r,c);
	}

	if(i<0 || i>=r || j<0 || j>=c)
		return INT_MIN;

	// if(dp1[i][j]!=-1)
	// 	return dp1[i][j];

	if(a[i][j]==0)
	{
		return dp1[i][j]=max(recur(a,i+1,j,r,c),recur(a,i,j+1,r,c));
	}
	else if(a[i][j]==1)
	{
		a[i][j]=0;
		int m1 = 1+recur(a,i+1,j,r,c);
		int m2 = 1+recur(a,i,j+1,r,c);
		a[i][j]=1;

		return dp1[i][j]=max(m1,m2);
	}
	/*a[i][j]==-1*/
	return INT_MIN;
}

int solve(vvi &a)
{
	int r=a.size();
	int c=a[0].size();
    
    if(r==1&&c==1)
    return a[0][0];
	
	memset(dp1,-1,sizeof(dp1));
    
	int m = recur(a,0,0,r,c);

	return m<0?0:m;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
	Output: 5*/

    vvi a = {
    	{0,1,-1},
    	{1,0,-1},
    	{1,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

