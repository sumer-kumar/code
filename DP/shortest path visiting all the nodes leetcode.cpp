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

/*try to do this using dfs*/

bool dp[13][13];
unordered_map<string,int> um;

string getHash(int mask,int nodes)
{
	return to_string(mask)+" "+to_string
}

int dfs(vvi &a,int curr,int nodes,vector<bool> &vis)
{
	/*base condition*/
	if(nodes == a.size())
	{
		return 0;
	}

	bool prev_status = vis[curr];
	vis[curr]=true;
	int res = 100000;
	for(auto x : a[curr])
	{
		if(dp[curr][x]==false)
		{
			dp[curr][x]=true;
			
			int curr_nodes = nodes;

			if(vis[x]==false)
				curr_nodes++;
			res = min(res,1 + dfs(a,x,curr_nodse,vis));
			dp[curr][x]=false;
		}
	}
	vis[curr]=prev_status;
	return res;
}

int solve(vvi &a)
{

	int size = a.size();

	int res = INT_MAX;
	memset(dp,false,sizeof(dp));
	vector<bool> vis(a.size(),false);

	rep(i,0,size-1)
	res = min(res,dfs(a,i,1,vis));

	return res;
}

// /*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: graph = [[1,2,3],[0],[0],[0]]
		Output: 4*/
    vvi a = {
    	{1,2,3},
    	{0},
    	{0},
    	{0}
    };

    /*Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
		Output: 4*/

    // vvi a = {
    // 	{1},
    // 	{0,2,4},
    // 	{1,3,4},
    // 	{2},
    // 	{1,2}
    // };


    cout<<solve(a)<<endl;

	return 0;
}

