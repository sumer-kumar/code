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
void showGraph(vector<pair<int,int>> a[],int V)
{
	// cout<<"Note : first element in bracket is edge second is weight\n";
	cout<<"Given Graph :--------> \n";

	for(int i=0;i<V;i++)
	{
		string str = "";

		cout<<i<<" : ";
		for(auto x : a[i])
		{
			str += "(" + to_string(x.first) + "," 
					+ to_string(x.second) +")"+ "-";
		}
		cout<<str.substr(0,str.size()-1)<<endl;
	}

	cout<<"--------------------->\n";
}

/*make dfs calls*/
int dp[111][111];
int recur(vector<pii> a[],int n,int curr,int dst,int k,vector<bool> &vis)
{
    if(curr==dst)
        return 0;

    if(k<0)
        return 10000000;

    if(dp[curr][k]!=-1)
    	return dp[curr][k];

    int mn = 10000000;
    /*try to take each flight from current*/
    for(auto x : a[curr])
    {
        if(vis[x.fi]==false)
        {
            // vis[curr]=true;
            mn=min(mn,x.se+recur(a,n,x.fi,dst,k-1,vis));
            // vis[curr]=false;
        }
    }

    return dp[curr][k]=mn;
}


int solve(vvi flights,int src,int dst,int n,int k)
{
	memset(dp,-1,sizeof(dp));

    /*make graph*/
    vector<pii> a[n]; /*dst price*/

    int size = flights.size();

    rep(i,0,size-1)
    {	/*   src                dst           price*/
        a[flights[i][0]].pb({flights[i][1],flights[i][2]});
    }

    vector<bool> vis(n,false);

    // showGraph(a,n);
    int t = recur(a,n,src,dst,k,vis);
    
    return t>=10000000?-1:t;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
		n = 3, 
		flights = [[0,1,100],[1,2,100],[0,2,500]], 
		src = 0, dst = 2, k = 1
    */
    /*
		n = 3, 
		flights = [[0,1,100],[1,2,100],[0,2,500]],
		src = 0, dst = 2, k = 0
    */

    int n=3;
    vvi flights = {
    	{0,1,100},
    	{1,2,100},
    	{0,2,500}
    };

    int src = 0;
    int dst = 2;

    int k = 1;

    cout<<solve(flights,src,dst,n,k)<<endl;

	return 0;
}

