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

int recur(vvi &dp,int r,int c,int i,int j,int n)
{
	if(r<0 || r>=n || c<0 || c>=n || dp[r][c]==0)
		return 0;

	if(dp[r][c]!=-1)
		return dp[r][c];

	return dp[r][c] = 1 + recur(dp,r+i,c+j,i,j,n);
}

int solve(vvi &mines,int n)
{
	vvi au(n+1,vi(n+1,-1));
	vvi ad(n+1,vi(n+1,-1));
	vvi ar(n+1,vi(n+1,-1));
	vvi al(n+1,vi(n+1,-1));

	int size = mines.size();

	rep(i,0,size-1)
	{
		au[mines[i][0]][mines[i][1]]=0;
		ad[mines[i][0]][mines[i][1]]=0;
		ar[mines[i][0]][mines[i][1]]=0;
		al[mines[i][0]][mines[i][1]]=0;
	}

	int mx = 0;

	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			int mn = n+1;
			mn = min(mn,recur(au,i,j,-1,0,n));
			mn = min(mn,recur(ad,i,j,1,0,n));
			mn = min(mn,recur(ar,i,j,0,1,n));
			mn = min(mn,recur(al,i,j,0,-1,n));

			cout<<"["<<i<<","<<j<<"]"<<" : "<<mn<<endl;

			mx = max(mx,mn);
		}
	}

	return mx;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n = 5, mines = [[4,2]]
    int n=2;
    vvi mines = {{0,1},{1,0},{1,1}};

    cout<<solve(mines,n)<<endl;

	return 0;
}

