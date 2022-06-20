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


void solve(vector<vector<char>> &a)
{
	for(int i=1;i<8;i++)
	{
		for(int j=1;j<9;j++)
		{
			if(a[i][j]=='#')
			{
				if(a[i-1][j-1]=='#' && a[i+1][j-1]=='#' && a[i-1][j+1]=='#' && a[i+1][j+1]=='#')
				{
					cout<<i+1<<" "<<j+1<<endl;
					return ;
				} 
			}
		}
	}
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	vector<vector<char>> a(8,vector<char>(8));

    	for(auto &x : a)
    	{
    		for(char &p : x)
    			cin>>p;
    	}

    	solve(a);
    }

	return 0;
}

