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

/*recursive approach*/
int recur(string a,string b,int aa,int bb)
{
	if(aa==0)
		return bb;
	if(bb==0)
		return aa;

	if(a[aa-1]==b[bb-1])
		return recur(a,b,aa-1,bb-1);

	return min(recur(a,b,aa-1,bb-1),min(recur(a,b,aa-1,bb),recur(a,b,aa,bb-1)))+1;
}

/*bottom up*/
int solve(string a,string b,int aa,int bb)
{
	int dp[aa+1][bb+1];

	rep(i,0,aa)
	{
		rep(j,0,bb)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else 
				dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
		}
	}
	return dp[aa][bb];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<recur(a,b,a.size(),b.size())<<endl;
    cout<<solve(a,b,a.size(),b.size())<<endl;

	return 0;
}

