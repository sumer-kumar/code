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

/*
1 ≤ T ≤100
1 ≤ A,B,C ≤10
1 ≤ X,Y,Z ≤10^6
*/

int dp[300][30][30][30];
int recur(int mins,int a,int b,int c,int x,int y,int z,int aa,int bb,int cc)
{
	// cout<<mins<<" "<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<endl;

	if(mins<=0)
		return 0;

	if(dp[mins][aa][bb][cc]!=-1)
		return dp[mins][aa][bb][cc];

	int res = 0;

	if(mins-a>=0 && aa>0)
		res = max(res,x + recur(mins-a,a,b,c,x,y,z,aa-1,bb,cc));

	if(mins-b>=0 && bb>0)
		res = max(res,y + recur(mins-b,a,b,c,x,y,z,aa,bb-1,cc));
	
	if(mins-c>=0 && cc>0)
		res = max(res,z + recur(mins-c,a,b,c,x,y,z,aa,bb,cc-1));
	
	return dp[mins][aa][bb][cc]=res;
}


int solve(int a,int b,int c,int x,int y,int z)
{
	memset(dp,-1,sizeof(dp));
	return recur(240,a,b,c,x,y,z,20,20,20);
	// return 0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	int a,b,c;
    	cin>>a>>b>>c;

    	int x,y,z;
    	cin>>x>>y>>z;

    	cout<<solve(a,b,c,x,y,z)<<endl;
    }

	return 0;
}

