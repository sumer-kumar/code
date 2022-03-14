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
typedef vector<vc> vvc;
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

void print(vvc &a)
{
	for(auto x : a)
	{
		for(char p : x)
			cout<<p<<" ";
		cout<<endl;
	}
	cout<<"\n";
}

void recur(vvc &a,int i,int j)
{
	int r = a.size();
	int c = a[0].size();

	if(i<0 || i>=r || j<0 || j>=c || a[i][j]!='O')
		return ;

	a[i][j]='#';

	recur(a,i+1,j);
	recur(a,i-1,j);
	recur(a,i,j+1);
	recur(a,i,j-1);
}

void solve(vvc &a)
{
	print(a);

	int r = a.size();
	int c = a[0].size();

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			if((i==0 || i==r-1 || j==0 || j==c-1) && a[i][j]=='O')
				recur(a,i,j);
		}
	}

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			if(a[i][j]=='O')
				a[i][j]='X';
			if(a[i][j]=='#')
				a[i][j]='O';
		}
	}

	print(a);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: board = [
    ["X","X","X","X"],
    ["X","O","O","X"],
    ["X","X","O","X"],
    ["X","O","X","X"]]*/

    vvc a = {
    	{'X','X','X','X'},
    	{'X','O','O','X'},
    	{'X','X','O','X'},
    	{'X','O','X','X'}
    };

    solve(a);

	return 0;
}

