#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define repl(i, a, b) for (ll i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

ll minCost(vll &a)
{
	int n = a.size();

	priority_queue<int,vector<int>,greater<int>> pq;

	repl(i,0,n-1)
		pq.push(a[i]);

	ll cost = 0;

	int u,v;
	while(pq.size()>1)
	{
		u = pq.top();
		pq.pop();
		
		v = pq.top();
		pq.pop();

		// cout<<u<<" "<<v<<endl;
		cost += (u+v);

		pq.push(u+v);
	}	

	return cost;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	vll a(n);

	repl(i,0,n-1)
		cin>>a[i];

	cout<<minCost(a)<<endl;

	return 0;
}