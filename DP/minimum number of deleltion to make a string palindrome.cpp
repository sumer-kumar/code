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

int solve(string a)
{
	int n = a.size();
	int dp[n+1][n+1];
	string b = a;
	/*reverse the copied string*/
	reverse(b.begin(),b.end());

	rep(i,0,n)
	{
		rep(j,0,n)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return a.size()-dp[n][n]; 
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

