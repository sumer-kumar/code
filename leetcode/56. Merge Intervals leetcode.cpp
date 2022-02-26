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

bool cmp(vi &a,vi &b)
{
	if(a[0]==b[0])
		return a[1]<b[1];
	return a[0]<b[0];
}

void solve(vvi &a)
{
	int size = a.size();
	sort(a.begin(),a.end(),cmp);

	vvi res;
	res.pb(a[0]);

	rep(i,1,size-1)
	{
		//if overllaping 
		if(a[i][0]<res.back()[1])
		{
			res.back()[1]=max(res.back()[1],a[i][1]);
		}
		else
		{
			res.pb(a[i]);
		}
	}

	for(auto x : res)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]*/

    vvi a = {
    	{1,3},
    	{2,6},
    	{8,10},
    	{15,18}
    };

    solve(a);

	return 0;
}

