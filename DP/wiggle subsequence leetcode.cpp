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
	state 0 : choose larger
	state 1 : choose smaller
*/

int dp[1111][1111][2];
int recur(vi &a,int curr,int last,int state)
{
	
	if(curr>=a.size())
		return 0;

	// cout<<curr<<" "<<last<<endl;

	if(dp[curr][last][state]!=-1)
		return dp[curr][last][state];

	cout<<curr<<" "<<last<<" "<<state<<endl;

	if(state==0)
	{
		if(a[curr]>last)
		{
			return dp[curr][last][state]=max(1+recur(a,curr+1,a[curr],1),recur(a,curr+1,last,state));
		}

		return dp[curr][last][state]=recur(a,curr+1,last,state);
	}
	else 
	{
		if(a[curr]<last)
		{
			return dp[curr][last][state]=max(1+recur(a,curr+1,a[curr],0),recur(a,curr+1,last,state));
		}
		return dp[curr][last][state]=recur(a,curr+1,last,state);
	}

}



int solve(vi &a)
{
	memset(dp,-1,sizeof(dp));
	int size = a.size();

	int res = 0;

	rep(i,0,size-1)
	{
		res = max(res,1+max(recur(a,i+1,a[i],0),recur(a,i+1,a[i],1)));
	}


	// return max(recur(a,0,0,0),recur(a,0,10000,1));
	return res;
}


int solve2(vi &aa)
{
	int size = aa.size();

	vi a;
	a.pb(aa[0]);

	rep(i,1,size-1)
	{
		if(a.back()==aa[i])
			continue;
		a.pb(aa[i]);
	}

	size = a.size();
	if(size<=2)
		return size;

	// for(int x : a)
	// 	cout<<x<<" ";
	// cout<<endl;

	int c_up = 0;
	int c_down = 0;

	vi dp(size,0);

	rep(i,1,size-2)
	{
		if(a[i]>a[i+1] && a[i]>a[i-1])
		{
			dp[i]=1;
			c_up++;
		}
		else if(a[i]<a[i+1] && a[i]<a[i-1])
		{
			dp[i]=-1;
			c_down++;
		}
	}


	// cout<<c_up<<" "<<c_down<<endl;

	return 2 + c_up + c_down;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,2,3,4,5,6,7,8,9};

    cout<<solve2(a)<<endl;

	return 0;
}

