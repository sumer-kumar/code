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

int dp[101][101][101];
int recur(vi &a,int i,int j,int cnt)
{

	if(i>j)
		return 0;

	if(dp[i][j][cnt]!=-1)
		return dp[i][j][cnt];

	int res = (cnt+1)*(cnt+1)+recur(a,i+1,j,0);

	rep(curr,i+1,j)
	{
		if(a[curr]==a[i])
		{
			res = max(res,recur(a,i+1,curr-1,0)+recur(a,curr,j,cnt+1));
		}
	}
	return dp[i][j][cnt]=res;
}

int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();

	return recur(a,0,size-1,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,3,2,2,2,3,4,3,1};

    cout<<solve(a)<<endl;

	return 0;
}

