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
	state 0 : we are try to make intials zeros (0000)
	state 1 : we are try to make final one's  (0001111111)
*/

int dp[100011][2];
int recur(string &a,int curr,int state)
{


	if(curr>=a.size())
		return 0;

	if(dp[curr][state]!=-1)
		return dp[curr][state];

	if(state == 0)
	{
		//we will try to keep it zero
		int m1 = (a[curr]=='1') + recur(a,curr+1,state); 

		//we will try to make it one
		int m2 = (a[curr]=='0') + recur(a,curr+1,!state);

		return dp[curr][state] = min(m1,m2);
	}
	else /*state ==  1*/
	{
		return dp[curr][state] = (a[curr]=='0') + recur(a,curr+1,state);
	}
}

/*order of o(N^2)*/
int solve(string a)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,0,0);
}

int one_in_left(vi &l,int curr)
{
	return l[curr];
}

int zero_in_right(vi &r,int curr)
{
	return r[curr+1];
}

int solve_2(string a)
{
	int size = a.size();
	vi l(size+1,0);
	vi r(size+1,0);

	//count ones on the left
	rep(i,1,size)
	{
		l[i] = l[i-1] + (a[i-1]=='1');
	}

	//count zeros on the right
	reverse(a.begin(),a.end());
	rep(i,1,size)
	{
		r[i] = r[i-1] + (a[i-1]=='0');
	}
	reverse(r.begin(),r.end());
	reverse(a.begin(),a.end());

	// for(int x : l)
	// 	cout<<x<<" ";
	// cout<<endl;

	// for(int x : r)
	// 	cout<<x<<" ";
	// cout<<endl;

	int res = size;
	rep(i,0,size-1)
	{
		// cout<<a[i]<<" "<<i<<" "<<one_in_left(l,i)<<" "<<zero_in_right(r,i)<<endl;
	 	res = min(res,one_in_left(l,i)+zero_in_right(r,i));
	}
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "000111";

    cout<<solve_2(a)<<endl;

	return 0;
}

