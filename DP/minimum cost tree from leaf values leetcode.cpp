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
	first = max_leaf_part
	second = min_sum_part
*/

pii dp[44][44];
pii recur(vi &a,int start,int end)
{
	if(start==end)
		return {a[start],0};

	if(dp[start][end]!=mp(-1,-1))
		return dp[start][end];

	int mx_leaf = INT_MIN;
	int mn_sum = INT_MAX;
	rep(i,start,end-1)
	{
		pii left = recur(a,start,i);
		pii right = recur(a,i+1,end);

		mx_leaf=max(left.fi,right.fi);
		mn_sum=min(mn_sum,left.fi*right.fi+left.se+right.se);
	}

	return dp[start][end]={mx_leaf,mn_sum};
}

int solve(vi &a)
{	
	for(int i=0;i<44;i++)
	{
		for(int j=0;j<44;j++)
		{
			dp[i][j]={-1,-1};
		}
	}

	return recur(a,0,a.size()-1).se;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {6,2,4};

    cout<<solve(a)<<endl;

	return 0;
}

