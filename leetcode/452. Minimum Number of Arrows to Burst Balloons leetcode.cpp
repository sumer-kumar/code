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


int solve(vvi &a)
{
	int size = a.size();
	sort(a.begin(),a.end());

	for(auto x : a)
	{
		for(auto p : x)
			cout<<p<<" ";
		cout<<endl;
	}

	int start = a[0][0];
	int end = a[0][1];
	int cnt = 0;
	
	/*now we have to check overlapping up to the extent and then count*/
	rep(i,1,size-1)
	{
		//non overlapping
		if(end<a[i][0])
		{
			cnt++;
			start=a[i][0];
			end=a[i][1];
		}
		else
		{
			start=max(start,a[i][0]);
			end=min(end,a[i][1]);
		}
	}

	return cnt+1;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2*/
    vvi a = {
    	{10,16},
    	{2,8},
    	{1,6},
    	{7,12}
    };
    /*
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]*/

    // vvi a = {
    // 	{9,12},
    // 	{1,10},
    // 	{4,11},
    // 	{8,12},
    // 	{3,9},
    // 	{6,9},
    // 	{6,7}
    // };

    cout<<solve(a)<<endl;

	return 0;
}

