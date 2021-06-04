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


/***********************NOT WORKING**********************/
int recur2(string a,string b,int aa,int bb)
{

	if(aa==0||bb==0)
		return 0;

	if(a[aa-1]==b[bb-1])
	{
		return 1+recur2(a,b,aa-1,bb)+recur2(a,b,aa,bb-1);
	}
	return recur2(a,b,aa-1,bb)+recur2(a,b,aa,bb-1)-recur2(a,b,aa-1,bb-1);
}

/*gfg solution*/
int dp[1001][1001];
int recur(string a,int i,int j)
{
	if(i>j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(i==j)
		return dp[i][j]=1;

	if(a[i]==a[j])
	{	int m1,m2;
		if(dp[i+1][j]!=-1)
			m1 = dp[i+1][j];
		else 
			m1 = recur(a,i+1,j);

		if(dp[i][j+1]!=-1)
			m2 = dp[i][j-1];
		else
			m2 = recur(a,i,j-1);
		return dp[i][j]=1+m1+m2;
	}

	int m1,m2,m3;
	if(dp[i+1][j]!=-1)
		m1 = dp[i+1][j];
	else 
		m1 = recur(a,i+1,j);

	if(dp[i][j+1]!=-1)
		m2 = dp[i][j-1];
	else
		m2 = recur(a,i,j-1);

	if(dp[i+1][j-1]!=-1)
		m3 = dp[i+1][j-1];
	else
		m3 = recur(a,i+1,j-1);

	return dp[i][j]=m1+m2-m3;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;

    memset(dp,-1,sizeof(dp));
    cout<<recur(a,0,a.size()-1)<<endl;

	return 0;
}

