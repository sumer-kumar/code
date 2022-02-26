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

void print(vvi &a)
{
	for(auto x : a)
	{
		for(int p : x)
			cout<<p<<' ';
		cout<<endl;
	}
}

void solve(vvi &a)
{
	int n = a.size();
	
	//first make transponse
	rep(i,0,n-1)
	{
		rep(j,0,i-1)
		{
			swap(a[i][j],a[j][i]);
		}
	}

	//swap the columns from right side to the left side

	rep(i,0,n/2)
	{
		rep(j,0,n-1)
		{
			swap(a[j][i],a[j][n-i-1]);
		}
	}

	print(a);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi a = {
    	{1,2,3},
    	{4,5,6},
    	{7,8,9}
    };

    solve(a);

	return 0;
}

