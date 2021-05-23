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
int rec2(string s,int ss,string r,int sr);
bool iskpali(string s,int k);


int pp=0;
/*recursive approach 1*/
bool recur(string s,int n,int k,int i=0)
{
	cout<<pp++<<" ";
	if(k<0)
		return false;

    if(i>=n-1 && k>=0)
		return true;
	
	/*when equal*/
	if(s[n-1]==s[i])
	{
		if(recur(s,n-1,k,i+1)==true)
			return true;
	}

	/*try remove ith element and check*/
	if(recur(s,n,k-1,i+1)==true)
		return true;

	/*try remove (n-1)th element*/
	if(recur(s,n-1,k-1,i)==true)
		return true;

	return false;
}
int dpsol(string s,int n,int k,vector<vector<int>>& dp,int i=0)
{
	if(k<0)
		return 0;

	if(i>=n-1 && k>=0)
		return 1;

	/*when equal */
	if(s[n-1]==s[i])
	{
		if(dp[i+1][n-1]==-1)
			dp[i+1][n-1] = dpsol(s,n-1,k,dp,i+1);
		if(dp[i+1][n-1]==1)
			return 1;
	}

	if(dp[i+1][n]==-1)/*uncalculated*/
		dp[i+1][n]=dpsol(s,n,k-1,dp,i+1);
	if(dp[i+1][n]==1)
		return 1;

	if(dp[i][n-1]==-1)
		dp[i][n-1]=dpsol(s,n-1,k-1,dp,i);
	if(dp[i][n-1]==1)
		return 1;

	return 0;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;

	string s;
	cin>>s;

	// cout<<s.size()<<"\n\n\n";

	// cout<<iskpali(s,n);
	// cout<<recur(s,s.size(),n)<<endl;

	vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
	cout<<dpsol(s,s.size(),n,dp)<<endl;


	rep(i,0,s.size())
	{
		rep(j,0,s.size())
		{
			printf("%3d",dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*recursive appracoh 2*/
int rec2(string s,int ss,string r,int sr)
{
	if(sr==0) return ss;
	if(ss==0) return sr;

	if(s[ss-1]==r[sr-1])
		return rec2(s,ss-1,r,sr-1);

	return 1 + min(rec2(s,ss-1,r,sr),rec2(s,ss,r,sr-1));
}

bool iskpali(string s,int k)
{
	string r = s;
	/*reverse r*/
	reverse(r.begin(),r.end());

	int changes = rec2(s,s.size(),r,r.size());

	if(changes <= k*2)
		return true;
	return false;
}