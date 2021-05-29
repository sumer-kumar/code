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
/**************************TLE ON GFG**************************/
void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

bool isPali(string &s,int i,int j)
{
	while(i<j)
	{
		if(s[i++]!=s[j--])
			return false;
	}
	return true;
}

/*recursive*/
int recur(string &s,int i,int j)
{	
	if(i>j)
		return 0;
	if(isPali(s,i,j))
		return 0;
	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		int t = recur(s,i,k)+recur(s,k+1,j)+1;
		ans = min(ans,t);
	}
	return ans;
}

/*memoization*/
vvi dp(1001,vi(1001,-1));
int solve(string &s,int i,int j)
{
	if(i>j)
		return 0;
	
	if(isPali(s,i,j))
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		// int t = recur(s,i,k)+recur(s,k+1,j)+1;
		int r,l;
		if(dp[i][k]!=-1)
			r=dp[i][k];
		else
			r=solve(s,i,k);

		if(dp[k+1][j]!=-1)
			l=dp[k+1][j];
		else 
			l=solve(s,k+1,j);

		ans = min(ans,l+r+1);
	}
	return dp[i][j] = ans;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    cout<<"bang"<<endl;
    cout<<recur(s,0,s.size()-1)<<endl;
    cout<<solve(s,0,s.size()-1)<<endl;

    rep(i,0,s.size())
    {
    	rep(j,0,s.size())
    	cout<<dp[i][j]<<" ";
    	cout<<endl;
    }

	return 0;
}

