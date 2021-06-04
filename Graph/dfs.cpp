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


void dfs(vector<int> a[],int curr,bool visited[])
{
	visited[curr]=true;
	cout<<curr<<" ";

	for(int x : a[curr])
	{
		if(!visited[x])
		dfs(a,i,visited);
	}
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*take graph input */
    int n=5;
    vector<int> a[5];
    bool visited[n]={false};

    for(int i=0;i<n;i++)
    {
    	if(!visited[i])
    	{
    		dfs(a,i,visited);
    	}
    }

	return 0;
}



