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

/*o(n^2)*/
/*int solve(vi &a,int diff)
{
	int size = a.size();
	vi dp(size,1);

	rep(i,1,size-1)
	{
		rep(j,0,i-1)
		{
			if(a[j]+diff==a[i])
			{
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}

	int mx = 1;
	for(int x : dp)
		mx = max(mx,x);

	return mx;
}	*/

/*o(n) space and time both*/
int solve(vi &a,int diff)
{
	unordered_map<int,int> um;

	int res = 1;
	/*the length of the arithmetic subsequence if it ends with current element*/
	for(int &x : a)
	{
		res = max(res,um[x] = 1 + um[x-diff]);
	}
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,5,7,8,5,3,4,2,1};
    int difference = -2;
    cout<<solve(a,difference)<<endl;
	return 0;
}

