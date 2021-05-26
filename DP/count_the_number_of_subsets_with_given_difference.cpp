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
/*count the number of subset of given sum*/
int countsubset(vi &a,int n,int sum)
{
	int dp[n+1][sum+1];
	cout<<"  ";
	rep(i,0,n)
	cout<<i<<" ";
	cout<<endl;

	rep(i,0,n)
	{
		cout<<i<<" ";
		rep(j,0,sum)
		{
			if(j==0)
				dp[i][j]=1;
			else if(i==0)
				dp[i][j]=0;
			else if(a[i-1]<=j)
				dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
			else 
				dp[i][j] = dp[i-1][j];

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][sum];
}

int solve(vi &a,int n,int diff)
{
	int sum = 0;
	rep(i,0,n-1)
	sum+=a[i];

	/*required sum to count the sum of subsets*/
	int rqsum = (diff+sum)/2;

	return countsubset(a,n,rqsum);
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

    int diff;
    cin>>diff;

    cout<<solve(a,n,diff)<<endl;

	return 0;
}

