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

int dp[1000][1000];
int recur(string &a,int start,int end)
{
	int m = 0;
	if(start==end)
		m= 1;

	else if(start>end)
		m= 0;

	else if(dp[start][end]!=-1)
		return dp[start][end];

	else if(a[start]==a[end])
		m=dp[start][end] = 1 + recur(a,start+1,end)+recur(a,start,end-1)-recur(a,start+1,end-1);
	else
	m=dp[start][end] = recur(a,start+1,end)+recur(a,start,end-1)-recur(a,start+1,end-1);

	cout<<start<<" "<<end<<" "<<m<<endl;

	return m;
}

int solve(string &a)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,a.size()-1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "fdsklf";

    cout<<solve(a)<<endl;
	
	return 0;
}

