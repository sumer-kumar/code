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
	state : 0 : previous element didn't swaped
	state : 1 : previous element swaped
*/

int recur(vi &a,vi &b,int curr,int state)
{
	if(state==0)
	{
		if(a[curr-1]>=a[curr] || b[curr-1]>=b[curr])
			return 100000;

		if(a[curr-1]<b[curr] && b[curr-1]<a[curr])
			return min(1+recur(a,b,curr+1,1),recur(a,b,curr+1,0));

		return recur(a,b,curr+1,0);
	}
	/*state == 1*/
	else
	{
		if(a[curr-1]>=b[curr] || b[curr-1]>=a[curr])
			return 100000;

		if(a[curr-1]<a[curr] && b[curr-1]<b[curr])
			return min(1+recur(a,b,curr+1,1),recur(a,b,curr+1,0));
	}
}

int solve(vi &a,vi &b)
{
	return recur(a,b,1,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
		Output: 1*/

    vi a = {1,3,5,4};
    vi b = {1,2,3,7};

    cout<<solve(a,b)<<endl;

	return 0;
}

