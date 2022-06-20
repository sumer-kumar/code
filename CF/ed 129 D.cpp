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

unordered_map<ll,ll> um;
unordered_map<ll,ll> um1;

int recur(ll n,ll x)
{
	cout<<x<<endl;
	string a = to_string(x);

	if(a.size()>=n)
		return 0;

	if(um.find(x)!=um.end())
		return um[x];

	if(um1.find(x)!=um1.end())
		return mod;

	int res = mod;

	um1[x]=1;
	for(char &p : a)
	{
		if(p!='1' && p!='0')
		{
			ll t = x*1ll*(p-'0');
			while(t%10==0)
				t/=10;
			res = min(res,1 + recur(n,t));
		}
	}

	return um[x] = res;
}

int solve(ll n,ll x)
{
	um.clear();

	//remove leading zeroes
	while(x%10==0)
		x/=10;

	cout<<x<<endl;

	return recur(n,x);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;

    cin>>n>>x;

    cout<<solve(n,x)<<endl;

	return 0;
}

