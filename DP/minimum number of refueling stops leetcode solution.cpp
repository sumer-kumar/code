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

/*public int minRefuelStops(int target, int startFuel, int[][] stations) 
{
    int N = stations.length;
    long[] dp = new long[N + 1];
    dp[0] = startFuel;
    for (int i = 0; i < N; ++i)
        for (int t = i; t >= 0; --t)
            if (dp[t] >= stations[i][0])
                dp[t+1] = Math.max(dp[t+1], dp[t] + (long) stations[i][1]);

    for (int i = 0; i <= N; ++i)
        if (dp[i] >= target) return i;
    return -1;
}
*/

void printVI(vll &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
}

int solve(vvi &a,int startFuel,int target)
{
	int size = a.size();
	vll dp(size+1,0);

	dp[0] = startFuel;

	rep(i,0,size-1)
	{
		for(int t=i;t>=0;t--)
		{
			if(dp[t]>=a[i][0])
			{
				dp[t+1] = max(dp[t+1],dp[t]+(ll)a[i][1]);
			}
		}
		printVI(dp);
	}

	rep(i,0,size)
	{
		if(dp[i]>=target)
			return i;
	}

	return -1;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2*/
/*100
50
[[50,50]]*/


    int target = 100;
    int startFuel = 10;
    vvi stations = {
    	{10,60},
    	{20,30},
    	{30,30},
    	{60,40}
    };

    cout<<solve(stations,startFuel,target)<<endl;

	return 0;
}

