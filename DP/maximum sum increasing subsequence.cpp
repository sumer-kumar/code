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


int solve(vi &a,int n)
{
	vi dp(a);

	int ans = 0;

	rep(i,1,n-1)
	{
		rep(j,0,i-1)
		{
			if(a[j]<a[i])
			{
				dp[i] = max(dp[i],dp[j]+a[i]);
			}
		}
	}

	for(int x : dp)
		ans = max(ans,x);

	return ans;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vi a(n);
    rep(i,0,n-1)
    cin>>a[i];

    cout<<solve(a,n)<<endl;


	return 0;
}

