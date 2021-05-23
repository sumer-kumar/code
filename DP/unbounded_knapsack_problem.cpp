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

/*recursive approach brute force*/
int recur(int w[],int v[],int n,int W)
{
	if(W<=0 || n<=0)
		return 0;
	
	cout<<w[0]<<" "<<v[0]<<" "<<n<<" "<<W<<endl;

	int inc=0;
	if(W-w[0]>=0)
	inc = v[0]+recur(w,v,n,W-w[0]);

	int exc = recur(w+1,v+1,n-1,W);


	return max(inc,exc);
}

/*memoization not working*/
int solve(int w[],int v[],int n,int W,int in[],int ex[])
{
	if(W<=0 || n<=0)
		return 0;
	cout<<W<<endl;

	if(W-w[0]>=0)
	{
		if(in[0]==-1)
			in[0] = v[0]+solve(w,v,n,W-w[0],in,ex);
	}

	if(ex[0]==-1)
		ex[0] = solve(w+1,v+1,n-1,W,in+1,ex+1);

	return max(in[0],ex[0]);
}

// /*recursion two vary the size of bag capacity from 0 to max */
// int rec2(int w[],int v[],int n,int W)
// {
// 	if(n<=0)
// 		return 0;

// 	int m = rec2(w,v,n,W-w[0]);
// }	

/*bottom up approach*/
int solve2(int w[],int v[],int n,int W)
{
	vi cap(W+1,0);
	rep(i,1,W)
	{
		rep(j,0,n-1)
		{
			if(i-w[j]>=0)
			{
				cap[i] = max(cap[i-w[j]]+v[j],cap[i]);
			}
		}
	}	
	// for(int x : cap)
	// 	cout<<x<<" ";
	// cout<<"\n";

	return cap[W];
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int v[n];	
	int w[n];

	rep(i,0,n-1)
	cin>>w[i]>>v[i];
	int W;
	cin>>W;

	cout<<solve2(w,v,n,W)<<endl;

	return 0;
}