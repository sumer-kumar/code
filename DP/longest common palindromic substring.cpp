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

int dp[1010][1010];
bool recur(string &a,int s,int e,int &res,string &ans)
{

	if(s>e)
	{
		return true;
	}

	if(dp[s][e]!=-1)
		return dp[s][e];

	if(a[s]==a[e])
	{
		if(recur(a,s+1,e-1,res,ans))
		{
			// res = max(res,e-s+1);
			if(res<e-s+1)
			{
				res = e-s+1;
				ans = a.substr(s,e-s+1);
			}

			// cout<<"------"<<res<<" "<<a.substr(s,e-s+1)<<endl;
			return dp[s][e]=true;
		}
	}

	recur(a,s+1,e,res,ans);
	recur(a,s,e-1,res,ans);


	return dp[s][e]=false;

}

string solve(string s)
{

	memset(dp,-1,sizeof(dp));
	int res = 0;
	string ans="";
	recur(s,0,s.size()-1,res,ans);

	return ans;

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "acaadbkaaca";

   	cout<<solve(s)<<endl;

	return 0;
}

