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

int recur(string &a,vi &sum,int curr,unordered_map<int,vi> &um)
{
	if(curr>=sum.size() || a[curr]==')')
		return 0;

	//find closing bracket for index curr
	auto t = upper_bound(um[sum[curr]-1].begin(),um[sum[curr]-1].end(),curr);
	int end = *t;

	cout<<curr<<" "<<end<<endl;

	if(curr+1==end)
		return 1+recur(a,sum,end+1,um);

	return 2*recur(a,sum,curr+1,um)+recur(a,sum,end+1,um);
}

int solve(string &a)
{
	int size = a.size();
	vi sum(size,0);
	sum[0]=1;

	rep(i,1,size-1)
	{
		sum[i] = sum[i-1]+(a[i]=='('?1:-1);
	}

	unordered_map<int,vi> um;

	rep(i,0,size-1)
	{
		um[sum[i]].pb(i);
	}

	return recur(a,sum,0,um);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "((())(()))";
    cout<<solve(a)<<endl;

	return 0;
}


