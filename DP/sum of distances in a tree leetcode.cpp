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

void showGraph(vector<int> a[],int V)
{

	int i=0;
	cout<<"Given Graph :--------> \n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" : ";
		for(int j = 0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------->"<<endl;

}
void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

/*
	first : sum of edges
	second : number of nodes inclusive

*/

string getHash(int curr,int parent)
{
	return to_string(curr)+" "+to_string(parent);
}

unordered_map<string,pii> um;
pii recur(vi a[],int curr,int parent)
{
	int child = 0;
	int sum = 0;

	string h = getHash(curr,parent);

	if(um.find(h)!=um.end())
		return um[h];

	for(int x : a[curr])
	{
		if(x!=parent)
		{
			pii t = recur(a,x,curr);
			sum += t.first + t.second;
			child += t.second;
		}
	}
	return um[h] = {sum,child+1};
}

int solve(vvi &A,int V)
{
	um.clear();
	/*make undirected graph*/
	vi a[V+1];
	for(auto x : A)
	{
		a[x[0]].pb(x[1]);
		a[x[1]].pb(x[0]);
	}

	vi res(V);

	rep(i,0,V-1)
		res[i] = recur(a,i,-1).fi;

	for(int x : res)
		cout<<x<<" ";

	cout<<endl;

	return 0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
		Output: [8,12,6,10,10,10]*/

    vvi a = {
    	{0,1},
    	{0,2},
    	{2,3},
    	{2,4},
    	{2,5}
    };

    int V = 6; /*means [0,5] */

    cout<<solve(a,V)<<endl;

	return 0;
}

