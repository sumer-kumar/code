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
int recur(string &a,string &b,int aa,int bb,int count=0)
{
	if(aa==0||bb==0)
		return count;

	if(a[aa-1]==b[bb-1])
	{
		int m1 = recur(a,b,aa-1,bb-1,count+1);
		count = max(count,m1);
		return count;
	}
	return max(count,max(recur(a,b,aa-1,bb,0),recur(a,b,aa,bb-1,0)));
}

/*using bottom up approach*/
int solve(string &a,string &b,int aa,int bb)
{
	int dp[aa+1][bb+1];

	int ml = 0;
	int l = 0;
	rep(i,0,aa)
	{
		rep(j,0,bb)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
				ml = max(ml,dp[i][j]);
			}
			else
				dp[i][j]=0;
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return ml;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    string b = a;
    cout<<"bang"<<endl;

    reverse(b.begin(),b.end());
    // cout<<recur(a,b,a.size(),b.size())<<endl;
    // cout<<memo(a,b,a.size(),b.size())<<endl;
    cout<<solve(a,b,a.size(),b.size())<<endl;
	return 0;
}

