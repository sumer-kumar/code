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


int dp[111][111];
int recur(vvi &a,int r,int c)
{
	if(r<0 || c<0)
		return 1000000;

	if(dp[r][c]!=-1)
		return dp[r][c];

	if(r==0&&c==0)
		return dp[r][c]=a[r][c];

	int t1 = recur(a,r-1,c);
	int t2 = recur(a,r,c-1);

	return dp[r][c]=a[r][c] + min(t1,t2);
}

int solve(vvi a)
{
	memset(dp,-1,sizeof(dp));
	int r = a.size();
	int c = a[0].size();

	return recur(a,r-1,c-1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//1,3,1],[1,5,1],[4,2,1
    vvi a = {
    //    0 1 2
    /*0*/{1,3,1},
    /*1*/{1,5,1},
    /*2*/{4,2,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

