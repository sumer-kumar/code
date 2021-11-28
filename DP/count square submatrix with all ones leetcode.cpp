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


int solve(vvi a)
{
	int r = a.size();
	int c = a[0].size();
		
	int res = 0;

	rep(i,0,r-1)
	{
		rep(j,0,c-1)
		{
			if(i==0||j==0)
				res += a[i][j];
			else if(a[i][j]==1)
			{
				res += a[i][j] = 1+min({a[i-1][j],a[i][j-1],a[i-1][j-1]});
			}
		}
	}
	return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*  [0,1,1,1],
	    [1,1,1,1],
        [0,1,1,1]*/

    vvi a = {
    	{0,1,1,1},
    	{1,1,1,1},
    	{0,1,1,1}
    };

    cout<<solve(a)<<endl;

	return 0;
}

