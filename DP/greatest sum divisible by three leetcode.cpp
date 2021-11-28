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
	our aim is to make a sum from after curr element such that sum%3= 3-rem
	for that we either include current element or exclude current element
*/
int dp[40001][3];
int recur(vi &a,int curr,int prev_rem)
{

	int req_rem = (3-prev_rem)%3;

	/*base condition*/
	if(curr>=a.size())
	{
		return 0;
	}

	if(dp[curr][prev_rem]!=-1)
		return dp[curr][prev_rem];

	/*if we are including current element*/
	int inc = a[curr] + recur(a,curr+1,(a[curr]+prev_rem)%3);
	if(inc%3!=req_rem)
		inc = 0;

	/*if we are excluding current element*/
	int exc = recur(a,curr+1,prev_rem);
	if(exc%3!=req_rem)
		exc = 0;

	/*return max of both w.r.t required remainder*/
	return dp[curr][prev_rem] = max(inc,exc);
}

int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();
	return recur(a,0,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {3,6,5,1,8};
    cout<<solve(a)<<endl;

	return 0;
}

