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


int solve(vi &a)
{
	int size = a.size();
	vector<bool> vis(size,false);

	queue<pii> q; /*first is index--second is jump*/
	q.push(mp(0,0));
	vis[0]=true;

	unordered_map<int,vi> um;

	rep(i,0,size-1)
	um[a[i]].pb(i);

	while(!q.empty())
	{
		pii t = q.front();
		q.pop();

		if(t.fi==size-1)
			return t.se;

		vi &next = um[a[t.fi]];
		next.pb(t.fi-1);
		next.pb(t.fi+1);

		for(int x : next)
		{
			if(x>=0 && x<size && vis[x]==false)
			{
				vis[x]=true;
				q.push(mp(x,t.se+1));
			}
		}
		next.clear();
	}
	return 0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3*/

    vi a = {100,-23,-23,404,100,23,23,23,3,404};
    // vi a = {7,7,2,1,7,7,7,3,4,1};
    //      0 1 2 3 4 5 6 7 8 9
    cout<<solve(a)<<endl;

	return 0;
}