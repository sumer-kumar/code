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
 
int dp[1001];
bool recur(string &a,int curr,unordered_map<string,vi> &um,int len,vvi &res)
{
	int size = a.size();
	//base case
	// cout<<curr<<" "<<size<<endl;
	if(curr>=size){
		cout<<len<<endl;
		return true;
	}
 
	if(dp[curr]!=-1)
		return dp[curr];

	//divide in part of two if can
	if(curr<=size-1)
	{
		if(um.find(a.substr(curr,2))!=um.end() && recur(a,curr+2,um,len+1,res))
		{
			res.pb(um[a.substr(curr,2)]);
			return true;
		}
	}
 
	//divide in part of three if can
	if(curr<=size-2)
	{
		if(um.find(a.substr(curr,3))!=um.end() && recur(a,curr+3,um,len+1,res))
		{
			res.pb(um[a.substr(curr,3)]);
			return true;
		}
	}
	return dp[curr]=false;
}
 
void solve(string &a,unordered_map<string,vi> &um)
{
	memset(dp,-1,sizeof(dp));
	vvi res;
	recur(a,0,um,0,res);
 
	int size = res.size();
	if(size==0)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		for(int i=size-1;i>=0;i--)
		{
			for(int x : res[i])
				cout<<x<<" ";
			cout<<endl;
		}
	}
}
 
/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin>>t;
 
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
		
		unordered_map<string,vi> um; //string - part of which
		rep(i,1,n)
		{
			string s;
			cin>>s;
 
			//divide in parts of two 
			rep(j,0,k-2)
			um[s.substr(j,2)]={j+1,j+2,i};
 
			//divide in parts of three
			rep(j,0,k-3)
			um[s.substr(j,3)]={j+1,j+3,i};
		}
		string a;
		cin>>a;
 
		solve(a,um);
    }
 
	return 0;
}