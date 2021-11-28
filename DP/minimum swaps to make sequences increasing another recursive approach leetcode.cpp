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
	state : 0 : previous didn't swapped
	state : 1 : previous swapped
*/

int dp[100001][2];
int recur(vi &a,vi &b,int curr,int prevA,int prevB,int state)
{

	if(curr==a.size())
		return 0;

	if(dp[curr][state]!=-1)
		return dp[curr][state];

	int res = 100000;
	/*check if the sequence is already correct*/
	if(a[curr]>prevA && b[curr]>prevB)
	{
		res = recur(a,b,curr+1,a[curr],b[curr],0);
	}

	/*swapped*/
	swap(a[curr],b[curr]);

	if(a[curr]>prevA && b[curr]>prevB)
	{
		/*add one for swapping */
		res = min(res,1 + recur(a,b,curr+1,a[curr],b[curr],1));
	}
	/*to form the original array*/
	swap(a[curr],b[curr]);

	return dp[curr][state]=res;
}

int solve(vi &a,vi &b)
{
	memset(dp,-1,sizeof(dp));
	return recur(a,b,0,-1,-1,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
	Output: 1
	Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
	Output: 1
	*/

    vi a = {0,3,5,8,9};
    vi b = {2,1,4,6,9};

    cout<<solve(a,b)<<endl;


	return 0;
}

