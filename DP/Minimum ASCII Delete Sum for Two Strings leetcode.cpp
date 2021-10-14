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

int dp[1111][1111];
int recur(string &a,string &b,int aa,int bb,vi &sa,vi &sb)
{	

	if(aa==0 && bb==0)
		return 0;

	if(aa==0)
		return sb[bb-1];

	if(bb==0)
		return sa[aa-1];

	if(dp[aa][bb]!=-1)
		return dp[aa][bb];

	if(a[aa-1]==b[bb-1])
	{
		return dp[aa][bb]=recur(a,b,aa-1,bb-1,sa,sb);
	}

	return dp[aa][bb]=min(a[aa-1]+recur(a,b,aa-1,bb,sa,sb),b[bb-1]+recur(a,b,aa,bb-1,sa,sb));
}

int solve(string &a,string &b)
{
	memset(dp,-1,sizeof(dp));

	int aa = a.size();
	int bb = b.size();

	vi sa(aa,0);
	vi sb(bb,0);

	sa[0]=a[0];
	rep(i,1,aa-1)
	sa[i]+=sa[i-1]+a[i];

	sb[0]=b[0];
	rep(i,1,bb-1)
	sb[i]+=sb[i-1]+b[i];

/*	for(int x : sa)
		cout<<x<<" ";
	cout<<endl;
	for(int x : sb)
		cout<<x<<" ";
	cout<<endl;
*/

	return recur(a,b,aa,bb,sa,sb);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "sea";
    string b = "eat";

    cout<<solve(a,b)<<endl;

	return 0;
}

