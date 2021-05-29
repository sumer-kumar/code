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
int i=0;
/*recursive approach*/
int recur(string &a,string &b,int aa,int bb)
{
	if(aa==0||bb==0)
		return 0;

	/*when characters matched*/
	if(a[aa-1]==b[bb-1])
	{
		/*move last pointer to the left of both string*/
		return 1+recur(a,b,aa-1,bb-1);
	}
	/*if not equal move last pointer of one string and remain same for other
	  and do the same for other*/
	return max(recur(a,b,aa,bb-1),recur(a,b,aa-1,bb));
}

/*memoization*/
vvi lp(1001,vi(1001,-1));
int memo(string &a,string &b,int aa,int bb)
{
	if(aa==0||bb==0)
		return 0;

	if(lp[aa][bb]!=-1)
		return lp[aa][bb];
	if(a[aa-1]==b[bb-1])
	{
		lp[aa][bb]=1+memo(a,b,aa-1,bb-1);
		return lp[aa][bb];
	}

	lp[aa][bb] = max(memo(a,b,aa,bb-1),memo(a,b,aa-1,bb));
	return lp[aa][bb];
}

/*using bottom up approach the real dp*/
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
				dp[i][j]= 1 + dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return aa+bb-dp[aa][bb];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;

    // cout<<recur(a,b,a.size(),b.size())<<endl;
    // cout<<memo(a,b,a.size(),b.size())<<endl;
    cout<<solve(a,b,a.size(),b.size())<<endl;


	return 0;
}

