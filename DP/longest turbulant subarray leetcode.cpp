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
	state : 0 : find smaller one from last
	state : 1 : find greater one from last
*/


/*
	dp memoisation not working 
	O(2^N) TLE
*/
int dp[5000][5000][2];
int recur(vi &a,int curr,int last,int state,int count)
{

	if(curr<0)
		return count;

	// if(dp[curr][last][state]!=-1)
	// 	return dp[curr][last][state];

	if(state==0)
	{	
		int m1=0,m2=0;
		if(a[curr]<a[last])
			m1 = recur(a,curr-1,curr,!state,count+1);

		count = max(count,m1);
		m2 = recur(a,curr-1,last,state,0);
		return dp[curr][last][state] = max(count,m2);
	}
	/*state == 1*/
	else
	{
		int m1=0,m2=0;
		if(a[curr]>a[last])
			m1 = recur(a,curr-1,curr,!state,count+1);
		m2 = recur(a,curr-1,last,state,0);

		return dp[curr][last][state] = max(m1,max(m2,count));
	}
}

int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();
	a.pb(INT_MIN);

	int m1 = recur(a,a.size()-2,a.size(),1,0);
	a[a.size()-1] = INT_MAX;
	int m2 = recur(a,a.size()-2,a.size(),0,0);
	a.pop_back();

	return max(m1,m2);
}

/*public int maxTurbulenceSize(vi  &A) {
    int inc = 1, dec = 1, result = 1;
    for (int i = 1; i < A.length; i++) {
        if (A[i] < A[i - 1]) {
            dec = inc + 1;
            inc = 1;
        } else if (A[i] > A[i - 1]) {
            inc = dec + 1;
            dec = 1;
        } else {
            inc = 1;
            dec = 1;
        }
        result = Math.max(result, Math.max(dec, inc));
    }
    return result;
}

int maxTurbulenceSize(vector<int>& A) {
    vector<vector<int>> dp(A.size(), vector<int>(2, 1));
    int res = 1;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > A[i - 1])
            dp[i][0] = dp[i - 1][1] + 1;
        else if (A[i] < A[i - 1]) 
            dp[i][1] = dp[i - 1][0] + 1;
        res = max(res, max(dp[i][0], dp[i][1]));   
    }
    return res;
}
*/

int solve2(vi &a)
{
	int size = a.size();

	vvi dp(2,vi(size,1));

	int res = 0;

	rep(i,1,size-1)
	{
		if(a[i]>a[i-1])
			dp[0][i] = dp[1][i-1]+1;
		else if(a[i]<a[i-1])
			dp[1][i] = dp[0][i-1]+1;

		res = max(res,max(dp[1][i],dp[0][i]));
	}

	return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {9,4,2,10,7,8,8,1,9};

    cout<<solve2(a)<<endl;

	return 0;
}

