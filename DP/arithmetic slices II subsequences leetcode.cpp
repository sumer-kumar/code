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


int solve(vi &a)
{
	int size = a.size();
	vector<unordered_map<ll,int>> dp(size);
	ll ans = 0;

	rep(i,1,size-1)
	{
		rep(j,0,i-1)
		{
			ll diff = (ll)a[i]-(ll)a[j];

			int sum = 0;

			if(dp[j].find(diff)!=dp[j].end())
			{
				sum = dp[j][diff];
			}
			dp[i][diff] += sum + 1;
			ans += sum;
		}
	}
	return (int)ans;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,4,6,8,10};

    cout<<solve(a)<<endl;

	return 0;
}

