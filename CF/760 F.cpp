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

unordered_set<ll> st;

int set_bit(ll x)
{
	int count = 0;

	while(x>0)
	{
		x = x&(x-1);
		count++;
	}

	return count;
}

ll rev(ll x)
{
	ll t = x;
	ll res = 0;

	while(t>0)
	{
		if(t&1)
			res = (res<<1)|1;
		else
			res = res<<1;
		t>>=1;
	}

	return res;
}

bool recur(ll x,ll y,int sb_x,int sb_y)
{

	if(sb_x>sb_y || x<0)
		return false;

	if(st.find(x)!=st.end())
	{
		return false;
	}

	st.insert(x);

	// reversing or adding 0 and then reversing both are same
	ll t = x;
	ll add_0 = rev(t);

	if(add_0==y)
		return true;

	t = (t<<1)|1;
	ll add_1 = rev(t);

	if(add_1 == y)
		return true;

	return recur(add_0,y,sb_x,sb_y) || recur(add_1,y,sb_x+1,sb_y);
}

string solve(ll x,ll y)
{
	st.clear();

	if(x==y)
		return "Yes";

	int sb_x = set_bit(x);
	int sb_y = set_bit(y);

	// cout<<rev(x)<<endl;

	// return "es";
	return recur(x,y,sb_x,sb_y)==true?"Yes":"No";
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x,y;

    cin>>x>>y;

    cout<<solve(x,y)<<endl;

	return 0;
}

