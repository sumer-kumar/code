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

void count_01(string &a,int &c0,int &c1)
{
	for(char x : a)
	{
		if(x=='0')
			c0++;
		else
			c1++;
	}
}

/*
	m & p.first = number of zeros
	n & p.second = number of ones

*/

int dp[666][111][111];
int recur(vector<pii> &a,int curr,int m,int n)
{

	if(curr==a.size())
		return 0;

	if(dp[curr][m][n]!=-1)
		return dp[curr][m][n];

	if(m-a[curr].fi>=0 && n-a[curr].se>=0)
	{
		return dp[curr][m][n] = max(
									1+recur(a,curr+1,m-a[curr].fi,n-a[curr].se),
									recur(a,curr+1,m,n)
								  );
	}

	return dp[curr][m][n]=recur(a,curr+1,m,n);
}

int solve(vector<string> &a,int m,int n)
{

	memset(dp,-1,sizeof(dp));
	vector<pii> b;

	int size = a.size();

	rep(i,0,size-1)
	{
		int c0=0,c1=0;
		count_01(a[i],c0,c1);

		b.pb({c0,c1});
	}


	return recur(b,0,m,n);

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*"10","0001","111001","1","0"*/

    vector<string> a = {
    	"10",
    	"0001",
    	"111001",
    	"1",
    	"0"
    };

/*
	m = number of zeros 
	n = number of ones
*/

    int m = 5;
    int n = 3;

    cout<<solve(a,m,n)<<endl;

	return 0;
}

