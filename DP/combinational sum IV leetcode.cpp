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


// int recur(vi &a,int n,int sum,string op= "")
// {
// 	// cout<<n<<" "<<sum<<endl;

// 	if(sum==0)
// 	{
// 		cout<<op<<endl;
// 		return 1;
// 	}

// 	if(n==0)
// 		return 0;

// 	if(sum-a[n-1]>=0)
// 	{
// 		return recur(a,n,sum-a[n-1],op+" "+to_string(a[n-1]))+recur(a,n-1,sum,op);
// 	}

// 	return recur(a,n-1,sum,op);
// }
int dp[1111];
int recur(vi &a,int sum)
{

	if(sum==0)
		return 1;

	if(dp[sum]!=-1)
		return dp[sum];

	int res = 0;

	for(int x : a)
	{
		if(sum-x>=0)
		{
			res += recur(a,sum-x);
		}
	}

	return dp[sum]=res;
}

int solve(vi &a,int n)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,n);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,2,3};
    int n = 4;

    cout<<solve(a,n)<<endl;

	return 0;
}

