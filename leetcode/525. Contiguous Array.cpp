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


int solve(vi &a)
{
	int size = a.size();
	vi sum(size+1,0);

	rep(i,0,size-1)
	sum[i+1]=sum[i]+(a[i]==0?-1:1);

	unordered_map<int,vi> um;
	
	rep(i,0,size)
	um[sum[i]].pb(i);

	int mx = 0;

	for(auto x : um)
	{
		mx = max(mx,x.se.back()-x.se[0]);
	}

	return mx;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {0,1,0};
    cout<<solve(a)<<endl;

	return 0;
}

