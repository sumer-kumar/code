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

/*least common subsequence*/
int solve(string &a,string &b,int aa,int bb)
{
	int dp[aa+1][bb+1];
	rep(i,0,aa)
	{
		rep(j,0,bb)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[aa][bb];
}

int fun(string &a,string &b)
{
	int lcs = solve(a,b,a.size(),b.size());

	int del = a.size()-lcs;
	int ins = b.size()-lcs;

	return del+ins;	
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;

    cout<<fun(a,b)<<endl;

	return 0;
}

