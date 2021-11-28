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

#define INF 100000

/*
	idea is to calculate all pair shortest path using floyed warshall algorithm
	after that calculate all the number of neighbours having shortest possible path 
	less than threshold distance
	and if cnt_i == cnt_j then return the maximum of i,j
*/

int solve(vvi &A,int n,int threshold)
{
	vvi a(n,vi(n,INF));

	int size = A.size();
	rep(i,0,size-1)
	{
		a[A[i][0]][A[i][1]] = A[i][2];
		a[A[i][1]][A[i][0]] = A[i][2];
	}

	rep(k,0,n-1)
	{
		rep(i,0,n-1)
		{
			rep(j,0,n-1)
			{
				if(i==j)
					a[i][j]=0;
				else
					a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
/*to print the distace matrix : a*/
/*	for(auto x : a)
	{
		for(int p : x)
		{
			if(p==INF)
				cout<<"I"<<" ";
			else
				cout<<p<<" ";
		}
		cout<<endl;
	}*/

	int res_cnt = INT_MAX;
	int res_node = -1;
	for(int i=n-1;i>=0;i--)
	{
		int cnt = 0;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]<=threshold)
			{
				cnt++;
			}
		}
		// cout<<i<<" "<<cnt<<endl;
		if(res_cnt>cnt)
		{
			res_cnt = cnt;
			res_node = i;
		}
	}

	return res_node;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*[[0,1,3],[1,2,1],[1,3,4],[2,3,1]],*/
    /*[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]*/
    int n = 4;
    vvi a = {
    	{0,1,3},
    	{1,2,1},
    	{1,3,4},
    	{2,3,1}
    	// {0,1,2},
    	// {0,4,8},
    	// {1,2,3},
    	// {1,4,2},
    	// {2,3,1},
    	// {3,4,1}
    };
    int threshold = 4;

    cout<<solve(a,n,threshold)<<endl;

	return 0;
}

