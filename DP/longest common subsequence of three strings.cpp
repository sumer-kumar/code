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

int solve(string &a,string &b,string &c,int aa,int bb,int cc)
{
	int dp[aa+1][bb+1][cc+1];

	rep(i,0,aa)
	{
		rep(j,0,bb)
		{
			rep(k,0,cc)
			{
				if(i==0||j==0||k==0)
					dp[i][j][k] = 0;
				else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				else
				{
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[aa][bb][cc];
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,c;
    cin>>a>>b>>c;

    cout<<solve(a,b,c,a.size(),b.size(),c.size())<<endl;

	return 0;
}

