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

void pp(vvi &a)
{
	for(auto x : a)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}
}

int solve(vvi &a)
{
	int r = a.size();
	int c = a[0].size();

	vvi h(r,vi(c,0));
	vvi v(r,vi(c,0));

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			if(a[i][j]==1)
			{
				h[i][j] = (j==0)?1:h[i][j-1]+1;
				v[i][j] = (i==0)?1:v[i-1][j]+1;
			}
		}
	}

	pp(h);
	cout<<endl;
	pp(v);
	cout<<endl;

	int mx_len = 0;

	//to calculate the length of the box
	for(int i=r-1;i>=0;i--)
	{
		for(int j=c-1;j>=0;j--)
		{
			int small = min(v[i][j],h[i][j]);
			while(small > mx_len)
			{
				if(v[i][j-small+1]>=small && h[i-small+1][j]>=small)
					mx_len = small;
				small--;
			}
		}
	}

	return mx_len*mx_len;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*grid = [[1,1,1],[1,0,1],[1,1,1]]*/
    vvi a = {
    	{1,1,1},
    	{1,0,1},
    	{1,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

