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

/*recursive approach*/
int recur(int a[],int n)
{	
	if(n==0)
		return 0;
	if(n==1)
		return a[0];
	if(n==2)
		return max(a[0],a[1]);

	/*when current element is choosen*/
	int m1 = a[0]+recur(a+2,n-2);

	/*when current element is not choosen*/
	int m2 = recur(a+1,n-1);

	return max(m1,m2);
}

/*memoization*/
int solve(int a[],int n,int in[],int ex[])
{
	if(n==0)
		return 0;
	if(n==1)
		return a[0];
	if(n==2)
		return max(a[0],a[1]);

	/*including condition*/
	if(in[0]==-1)
		in[0] = a[0]+solve(a+2,n-2,in+2,ex+2);

	if(ex[0]==-1)
		ex[0] = solve(a+1,n-1,in+1,ex+1);

	return max(in[0],ex[0]);
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];

	rep(i,0,n-1)
	cin>>a[i];

	// cout<<recur(a,n)<<endl;	

	int ex[n];
	int in[n];
	memset(ex,-1,sizeof(ex));
	memset(in,-1,sizeof(in));

	cout<<solve(a,n,in,ex)<<endl;

		return 0;
}