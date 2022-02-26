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
		for(auto p : x)
			cout<<p<<" ";
		cout<<endl;
	}
}

void recur(vi &a,vi &vis,vvi &res,vi &curr)
{
	int size = a.size();

	if(size==curr.size())
	{
		res.pb(curr);
		return;
	}

	rep(i,0,size-1)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			curr.pb(a[i]);
			recur(a,vis,res,curr);
			curr.pop_back();
			vis[i]=0;
		}
	}
}

void solve(vi &a)
{
	int size = a.size();
	vvi res;
	vi vis(size+1,0);
	vi curr;
	recur(a,vis,res,curr);
	print(res);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/

    vi a = {1,2,3};

 	solve(a);   

	return 0;
}

