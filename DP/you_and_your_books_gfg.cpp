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

int solve(vi &a,int n,int k)
{
	int curr = 0;
	int maxs = 0;
	rep(i,0,n-1)
	{
		// cout<<curr<<" : "<<maxs<<endl;
		if(a[i]>k)
		{
			maxs = max(maxs,curr);
			curr = 0;
		}
		else
		{
			curr += a[i];
		}
	}

	return max(maxs,curr);
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;
	cin>>n>>k;

	vi a(n);
	rep(i,0,n-1)
	cin>>a[i];

	cout<<solve(a,n,k)<<endl;

	return 0;
}