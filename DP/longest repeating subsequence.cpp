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

int solve(string &a)
{
	int aa = a.size();
	int dp[aa+1][aa+1];
	rep(i,0,aa)
	{
		rep(j,0,aa)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==a[j-1] && i!=j)
				dp[i][j]= 1 + dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[aa][aa];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;

    cout<<solve(a)<<endl;


	return 0;
}

