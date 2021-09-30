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
	state 0 : first players turn
	state 1 : second players turn
*/

int dp[22][22][2];
int recur(vi &a,int front, int end,bool state)
{

	if(front>end)
		return 0;

	if(dp[front][end][state]!=-1)
		return dp[front][end][state];

	if(state == 0)
	{
		int m1 = a[front]+recur(a,front+1,end,!state);
		int m2 = a[end]+recur(a,front,end-1,!state);

		return dp[front][end][state]=max(m1,m2);
	}
	else
	{
		int m1 = -a[front]+recur(a,front+1,end,!state);
		int m2 = -a[end]+recur(a,front,end-1,!state);

		return dp[front][end][state]=min(m1,m2);
	}
}


int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();

	cout<<recur(a,0,a.size()-1,0)<<endl;

	return recur(a,0,a.size()-1,0)<0?0:1;

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,4,55,6};

    cout<<solve(a)<<endl;

	return 0;
}

