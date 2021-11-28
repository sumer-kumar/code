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
	our main idea is to calculate distances of all 1 from 0's
	simultaneously using bfs level by level
	and choose the maximum one
*/

int solve(vvi a)
{
	/*push all the ones in the queue to start the bfs*/
	queue<pii> q;
	int n = a.size();

	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			if(a[i][j]==1)
				q.push(mp(i,j)); 
		}
	}

	/*if queue is empty : there is not a single 1*/
	/*if size of queue is equal to no. of cells in the grid : then there are not a single water*/
	if(q.size()==0 || q.size()==n*n)
	return -1;

	int level = 0;
	vi r = {1,-1,0,0};
	vi c = {0,0,1,-1};

	while(!q.empty())
	{
		level++;
		int curr_size = q.size();

		while(curr_size--)
		{
			pii t= q.front();
			q.pop();
			for(int k=0;k<4;k++)
			{
				/*next cell to check with index n_i,n_j*/
				int n_i = t.fi+r[k]; 
				int n_j = t.se+c[k];
				if(n_i<0 || n_i>=n || n_j<0 || n_j>=n || a[n_i][n_j]==1)
					continue;
				q.push({n_i,n_j});
				a[n_i][n_j]=1;
			}
		}
	}

	return level-1; //because in starting we have choose level 0
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi a = {
    	{1,0,1},
    	{0,0,0},
    	{1,0,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

