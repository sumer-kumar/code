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

int recur2(vvi &a,int i,int j,int r,int c)
{
	if(j<0 || j>=c)
		return INT_MIN;
	if(i==r)
	{
		return 0;
	}

	int t=0;
	swap(a[i][j],t);

	int m1 = t+recur2(a,i+1,j,r,c);
	int m2 = t+recur2(a,i+1,j-1,r,c);
	int m3 = t+recur2(a,i+1,j+1,r,c);

	swap(a[i][j],t);

	return max({m1,m2,m3});
}


int recur(vvi &a,int i,int j,int r,int c)
{
	if(j<0 || j>=c)
		return INT_MIN;
	if(i==r)
	{
		return recur2(a,0,c-1,r,c);
	}

	int t=0;
	swap(a[i][j],t);

	int m1 = t+recur(a,i+1,j,r,c);
	int m2 = t+recur(a,i+1,j-1,r,c);
	int m3 = t+recur(a,i+1,j+1,r,c);

	swap(a[i][j],t);

	return max({m1,m2,m3});
}

int solve(vvi &a)
{
	return recur(a,0,0,a.size(),a[0].size());
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
	Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
	Output: 24
    */

    vvi a = {
    	{3,1,1},
    	{2,5,1},
    	{1,5,5},
    	{2,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

