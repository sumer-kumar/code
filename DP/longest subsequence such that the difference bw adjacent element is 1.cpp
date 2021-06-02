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

int recur(vi &a,int n,int prev = INT_MIN)
{
	if(n==0)
		return 0;

	if(prev==INT_MIN || abs(prev-a[n-1])==1)
	{
		return max(1+recur(a,n-1,a[n-1]),recur(a,n-1,prev));
	}
	return recur(a,n-1,prev);
}


int solve(vi& a,int n)
{
	vi dp(n+1,1);

	rep(i,1,n-1)
	{
		rep(j,0,i-1)
		{
			if(abs(a[i]-a[j])==1)
			{
				dp[i] = max(dp[i],1+dp[j]);
			}
		}
	}

	int ans = 0;

	for(int x : dp)
	{
		// cout<<x<<" ";
		ans = max(ans,x);
	}

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

    cout<<recur(a,n)<<endl;
    cout<<solve(a,n)<<endl;


	return 0;
}

